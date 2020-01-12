#include "Tweener.h"
#include "math.h"

std::vector<Tweener::Tween*> Tweener::tweens;

Tweener::Easing_Function Tweener::easing_function_list[] =
{
	polynomial,
	sine,
	elastic,
	bounce
};

void Tweener::tween(int* target, const int& new_val, const unsigned int duration, const Ease ease, const Ease_Type type)
{
	Tween* new_tween = new Tween(
	{
		target,
		*target,
		new_val,
		new_val - *target,
		duration,
		Details::now,
		Details::now + duration,
		ease,
		type,
		easing_function_list[ease]
	});

	bool exists = false;

	for (auto& tween : tweens)
	{
		if (tween->target = new_tween->target)
		{
			tween = new_tween;
			exists = true;
		}
	}

	if (!exists)
	{
		tweens.push_back(new_tween);
	}
}

void Tweener::update()
{
	for (std::vector<Tween*>::iterator it = tweens.begin(); it != tweens.end();)
	{
		int elapsed_time = Details::now - it[0]->end_time;

		if (elapsed_time > it[0]->duration)
		{
			*it[0]->target = it[0]->new_val;
			it = tweens.erase(it);
		}
		else
		{
			float percent_complete =
				Details::now < it[0]->end_time
				?
				elapsed_time / it[0]->duration
				:
				1
				;

			Ease_Type temp_type = it[0]->type != INOUT ? it[0]->type : percent_complete < 0.5 ? IN : OUT;

			*it[0]->target = it[0]->ease_func(percent_complete, elapsed_time, it[0]->old_val, it[0]->new_val, it[0]->duration, temp_type);

			++it;
		}
	}
}

//y = x^n
int polynomial(float percent_complete, int old_val, int new_val, int delta_val, int modifier = 1, Ease_Type type = IN)
{
	return type == IN
		? 
		old_val + delta_val * pow(percent_complete, modifier)
		: 
		old_val + delta_val * (1 - pow(percent_complete, modifier))
		;
}
//y = sine(2 / PI * x), only uses first quarter of graph
int sine(float percent_complete, int old_val, int new_val, int delta_val, int modifier = 1)
{
	return old_val + delta_val * sin(PI / 2 * percent_complete);
}
//y = elastic_curve(x)
int elastic(float percent_complete, int old_val, int new_val, int delta_val, int modifier = 2 * PI / 4.5, Ease_Type type = IN)
{
	int elastic_const = modifier;

	return percent_complete == 0
		? old_val
		: percent_complete == 1
		? new_val
		: type == IN
		? old_val - (pow(2, 20 * percent_complete - 10) * sin((20 * percent_complete - 11.125) * elastic_const)) / 2		//exponential graph * inverse sine
		: old_val + (pow(2, -20 * percent_complete + 10) * sin((20 * percent_complete - 11.125) * elastic_const)) / 2 + 1;	//exponential graph * sine
}
//y = bounce_curve(x)
int bounce(float percent_complete, int old_val, int new_val, int delta_val, int modifier = 2 * PI / 4.5, Ease_Type type = IN)
{
	return type == IN
		?
		old_val + delta_val * (1.0 - bounceOut(1.0 - 2.0 * percent_complete)) / 2.0
		:
		old_val + delta_val * (1.0 + bounceOut(2.0 * percent_complete - 1.0)) / 2.0
		;
}
//helper function for bounce
float bounceOut(float x)
{
	float n1 = 7.5625;
	float d1 = 2.75;

	if (x < 1.0 / d1) {
		return n1 * x * x;
	} 
	else if (x < 2.0 / d1) {
		return n1 * (x -= 1.5 / d1) * x + 0.75;
	} 
	else if (x < 2.5 / d1) {
		return n1 * (x -= 2.25 / d1) * x + 0.9375;
	} 
	else {
		return n1 * (x -= 2.625 / d1) * x + 0.984375;
	}
}
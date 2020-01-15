#include "Tweener.h"
#include "Easing_Functions.h"

std::vector<Tweener::Tween*> Tweener::tweens;

Tweener::Easing_Function Tweener::easing_function_list[] =
{
	polynomial,
	sine,
	elastic,
	bounce
};

void Tweener::tween(int* target, const int& new_val, const int duration, const Ease ease, const Ease_Type type)
{
	Tween* new_tween = new Tween(
	{
		target,
		*target,
		new_val,
		new_val - *target,
		duration,
		Universe::now,
		Universe::now + duration,
		ease,
		type,
		easing_function_list[ease]
	});

	bool exists = false;

	for (auto& tween : tweens)
	{
		if (tween->target == new_tween->target)
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
		int elapsed_time = Universe::now - it[0]->end_time;

		if (elapsed_time > it[0]->duration)
		{
			*it[0]->target = it[0]->new_val;
			it = tweens.erase(it);
		}
		else
		{
			float percent_complete =
				Universe::now < it[0]->end_time
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
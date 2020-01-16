#include "Easing_Functions.h"
#include "math.h"

Easing_Function easing_function_list[] =
{
	polynomial,
	sine,
	elastic,
	bounce
};

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
//y = sine(2 / 3.14159 * x), only uses first quarter of graph
int sine(float percent_complete, int old_val, int new_val, int delta_val, int modifier = 1, Ease_Type type = IN)
{
	return old_val + delta_val * sin(3.14159 / 2 * percent_complete);
}
//y = elastic_curve(x)
int elastic(float percent_complete, int old_val, int new_val, int delta_val, int modifier = 2 * 3.14159 / 4.5, Ease_Type type = IN)
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
int bounce(float percent_complete, int old_val, int new_val, int delta_val, int modifier = 2 * 3.14159 / 4.5, Ease_Type type = IN)
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
		x -= 1.5;
		return n1 * (x / d1) * x + 0.75;
	}
	else if (x < 2.5 / d1) {
		x -= 2.25;
		return n1 * (x / d1) * x + 0.9375;
	}
	else {
		x -= 2.625;
		return n1 * (x / d1) * x + 0.984375;
	}
}
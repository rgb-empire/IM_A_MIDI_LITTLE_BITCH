#include "Tweener.h"

int Tweener::(*ease_functions[])(int,int,float) =
{
	linear,
	sine,
	quad,
	cubic,
	quart,
	quint
};

void Tweener::tween(int& target, const int& new_val, const unsigned int duration, const Ease ease, const EaseType type)
{
	Tween new_tween =
	{
		target,
		target,
		new_val,
		duration,
		Details::now,
		Details::now + duration,
		0,
		ease,
		type,
		ease_functions[ease]
	};

	tweens.push_back(new_tween);
}

void Tweener::update()
{
	for (auto& tween : tweens)
	{
		float percent_complete = 
			Details::now < tween.end_time
			?
				tween.duration / (Details::now - tween.start_time)
			:
				1
			;

		tween.target = tween.ease_func(tween.old_val, tween.new_val, percent_complete);
	}
}

int linear(int start, int end, float percent_complete)
{

}

int sine(int start, int end, float percent_complete)
{

}

int quad(int start, int end, float percent_complete)
{

}

int cubic(int start, int end, float percent_complete)
{

}

int quart(int start, int end, float percent_complete)
{

}

int quint(int start, int end, float percent_complete)
{

}
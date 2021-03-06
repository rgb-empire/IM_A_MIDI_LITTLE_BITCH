#include "Tweener.h"
#include "Easing_Functions.h"

std::vector<Tweener::Tween*> Tweener::tweens;

void Tweener::tween(int* target, const int& new_val, const int duration, const Ease ease, const Ease_Type type, Callback callback)
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
		easing_function_list[ease],
		callback
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
		int elapsed_time = Universe::now - (*it)->start_time;

		if (elapsed_time > (*it)->duration)
		{
			*(*it)->target = (*it)->new_val;

			Callback cb = (*it)->cb;

			it = tweens.erase(it);

			if (cb != NULL)
			{
				cb();
			}
		}
		else
		{
			float percent_complete =
				Universe::now < (*it)->end_time
				?
				(float)elapsed_time / (float)(*it)->duration
				:
				1
				;

			*(*it)->target = (*it)->ease_func(percent_complete, (*it)->old_val, (*it)->new_val, (*it)->delta_val, 1, IN);

			++it;
		}
	}
}
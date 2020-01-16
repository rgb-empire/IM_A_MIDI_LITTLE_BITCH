#pragma once

#include "Global_Definitions.h"

class Tweener
{
public:
	
	static void tween(int* target, const int& new_val, const int duration = 2000, const Ease ease = LINEAR, const Ease_Type type = INOUT, Callback callback = NULL);

	static void update();

protected:

	struct Tween {
		int* target;
		int old_val;
		int new_val;
		int delta_val;
		int duration;
		long start_time;
		long end_time;

		Ease ease;
		Ease_Type type;
		Easing_Function ease_func;

		Callback cb;
	};

	static std::vector<Tween*> tweens;
};
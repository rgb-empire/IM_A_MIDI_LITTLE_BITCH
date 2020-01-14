#pragma once

#include "Global_Definitions.h"

class Tweener
{
public:
	
	static void tween(int* target, const int& new_val, const int duration = 2000, const Ease ease = LINEAR,  const Ease_Type type = INOUT);

	static void update();

protected:
	typedef int (*Easing_Function)(float, int, int, int, int, Ease_Type);

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
	};

	static std::vector<Tween*> tweens;

	static Easing_Function easing_function_list[];
};
#pragma once

#include <vector>
#include "Details.h"

enum Ease { LINEAR, SINE, QUAD, CUBIC, QUART, QUINT };
enum Ease_Type { IN, OUT, INOUT };

class Tweener
{
public:
	
	static void tween(int* target, const int& new_val, const unsigned int duration = 2000, const Ease ease = LINEAR,  const Ease_Type type = INOUT);

	static void update();

protected:
	typedef int (*Easing_Function)(float, int, int, int, int, Ease_Type);

	struct Tween {
		int* target;
		int old_val;
		int new_val;
		int delta_val;
		unsigned int duration;
		unsigned long start_time;
		unsigned long end_time;

		Ease ease;
		Ease_Type type;
		Easing_Function ease_func;
	};

	static std::vector<Tween*> tweens;

	static Easing_Function easing_function_list[];
};
#pragma once

#include <vector>
#include "Details.h"

class Tweener
{
public:
	enum Ease { LINEAR, SINE, QUAD, CUBIC, QUART, QUINT };
	enum EaseType { IN, OUT, INOUT, NONE };

	static void tween(int& target, const int& new_val, const unsigned int duration);

	static void update();

protected:

	struct Tween {
		int& target;
		int old_val;
		int new_val;
		unsigned int duration;
		unsigned long start_time;
		unsigned long end_time;
		unsigned long last_update;

		Ease ease;
		EaseType type;
	};

	static std::vector<Tween> tweens;
};

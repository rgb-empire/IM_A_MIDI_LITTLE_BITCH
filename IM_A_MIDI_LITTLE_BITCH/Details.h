#pragma once

#include "Fader.h"

class Details
{
public:
	static long now;

	accum1616 bpm;
	unsigned int beat_time;

	//test test

	unsigned int last_beat;
	unsigned int next_beat;
	
	static void update();
	static void update_bpm(accum1616 new_bpm);
	static int beat_duration(const int new_num_beats = 1);
};


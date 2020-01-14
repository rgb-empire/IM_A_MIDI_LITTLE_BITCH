#pragma once

#include "Global_Definitions.h"

class Velocity
{
public:
	static long now;

	static int bpm;
	static int beat_time;

	static long last_beat;
	static long next_beat;
	
	static void loop();
	static void update_bpm(int new_bpm, int duration = 2000);
	static int beat_duration(const int new_num_beats = 1);
	static int duration;
};
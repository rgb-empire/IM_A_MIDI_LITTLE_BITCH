#pragma once

#include "Global_Definitions.h"

class Universe
{
public:
	static long now;

	static int bpm;
	static int beat_time;

	static long last_beat;
	static long next_beat;
	static int time_to_last;
	static int time_to_next;
	
	static bool pre_beat;
	static bool beat;

	static int num_beats;

	static void loop();
	static void update_bpm(int new_bpm, int duration = 2000);
	static int beat_duration(const int new_num_beats = 1);
	static int duration;

};
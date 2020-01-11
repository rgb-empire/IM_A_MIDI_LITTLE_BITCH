#pragma once

class Details
{
public:
	static long now;

	static int bpm;
	static int beat_time;

	static unsigned int last_beat;
	static unsigned int next_beat;
	
	static void loop();
	static void update_bpm(int new_bpm, int duration = 2000);
	static int beat_duration(const int new_num_beats = 1);
	static int duration;
};
#include "Universe.h"

long Universe::now = 0;

int Universe::bpm = 120;
int Universe::beat_time = int(60000 / Universe::bpm);
long Universe::last_beat = 0;
long Universe::next_beat = 0;
int Universe::time_to_last = 0;
int Universe::time_to_next = 0;
bool Universe::pre_beat = true;
bool Universe::beat = false;

int Universe::num_beats = 0;

void Universe::loop()
{
	now = millis();

	beat_time = 60000 / bpm;

	last_beat = now - now % beat_time;
	next_beat = last_beat + beat_time;

	time_to_last = now - last_beat;
	time_to_next = next_beat - now;

	if (beat == true)
	{
		beat = false;
	}

	if (time_to_last > time_to_next)
	{
		pre_beat = true;
	}

	if (time_to_last < time_to_next && pre_beat == true)
	{
		beat = true;
		pre_beat = false;
	}
}

void Universe::update_bpm(int new_bpm, int duration)
{
	Tweener::tween(&bpm, new_bpm, duration);
}

int Universe::beat_duration(const int new_num_beats)
{
	return beat_time * new_num_beats;
}


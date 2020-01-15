#include "Universe.h"

long Universe::now = 0;

int Universe::bpm = 120;
int Universe::beat_time = int(60000 / Universe::bpm);
long Universe::last_beat, Universe::next_beat = 0;

void Universe::loop()
{
	now = millis();

	beat_time = 60000 / bpm;

	last_beat = now - now % beat_time;
	next_beat = last_beat + beat_time;
}

void Universe::update_bpm(int new_bpm, int duration)
{
	Tweener::tween(&bpm, new_bpm, duration);
}

int Universe::beat_duration(const int new_num_beats)
{
	return beat_time * new_num_beats;
}
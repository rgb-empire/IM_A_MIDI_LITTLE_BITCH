#include "Universe.h"

long Velocity::now = 0;

int Velocity::bpm = 120;
int Velocity::beat_time = int(60000 / Velocity::bpm);
long Velocity::last_beat, Velocity::next_beat = 0;

void Velocity::loop()
{
	now = millis();

	beat_time = 60000 / bpm;

	last_beat = now - now % beat_time;
	next_beat = last_beat + beat_time;
}

void Velocity::update_bpm(int new_bpm, int duration)
{
	Tweener::tween(&bpm, new_bpm, duration);
}

int Velocity::beat_duration(const int new_num_beats)
{
	return beat_time * new_num_beats;
}
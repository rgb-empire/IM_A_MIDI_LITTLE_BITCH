#include "Details.h"

long Details::now = 0;

int bpm = 120;
int Details::beat_time = int(60000 / Details::bpm);
int last_beat, next_beat = 0;

void Details::loop()
{
	now = millis();

	beat_time = 60000 / Details::bpm;

	last_beat = now - now % beat_time;
	next_beat = last_beat + beat_time;
}

void Details::update_bpm(int new_bpm, int duration)
{
	Tweener::tween(Details::bpm, new_bpm, duration);
}

int Details::beat_duration(const int new_num_beats)
{
	return beat_time * new_num_beats;
}
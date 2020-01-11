#include "Details.h"

long Details::now = 0;

Fader<accum1616> Details::bpm = Fader<accum1616>(120 * UINT16_MAX);
Fader<int> Details::beat_time = Fader<int>(60000 / Details::bpm.cur_value);

void Details::update()
{
	now = millis();

	beat_time.cur_value = 60000 / bpm.cur_value;

	last_beat.cur_value = now - now % beat_time.cur_value;
	next_beat.cur_value = last_beat.cur_value + beat_time.cur_value;
}

void Details::update_bpm(accum1616 new_bpm)
{
	bpm.fade(new_bpm);
}

int Details::beat_duration(const int new_num_beats)
{
	return beat_time.cur_value * new_num_beats;
}

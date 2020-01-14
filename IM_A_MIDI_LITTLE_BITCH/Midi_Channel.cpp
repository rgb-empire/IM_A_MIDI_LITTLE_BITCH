#include "Midi_Channel.h"

extern CRGBArray<NUM_LEDS> gleds;

Midi_Channel::Midi_Channel()
{
}

Midi_Channel::~Midi_Channel()
{
}

void Midi_Channel::loop()
{
	// Does anything even happen here?
}

void Midi_Channel::map_leds(const int start, const int end)
{
	shadows.push_back({start, end, abs(end - start)});
}

void Midi_Channel::render(const fract16 alpha)
{
	for (shadow & shadow : shadows)
	{
		if (shadow.start < shadow.end) //forward
		{
			for (int i = 0; i < shadow.len; i++)
			{
				gleds[shadow.start + i] = my_leds[shadow.start + i];
			}
		}
		else //backward
		{
			for (int i = 0; i < shadow.len; i++)
			{
				gleds[shadow.end - i] = my_leds[shadow.start + i];
			}
		}
	}
}

void Midi_Channel::set_program(const byte new_program)
{
	old_program = program;
	program = new_program;

	fade_fract = 0;

	Tweener::tween(&fade_fract, UINT16_MAX);
}

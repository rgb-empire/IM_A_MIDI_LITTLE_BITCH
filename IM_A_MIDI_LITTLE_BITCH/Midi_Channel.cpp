#include "Midi_Channel.h"

Midi_Channel::Midi_Channel()
{
}

Midi_Channel::~Midi_Channel()
{
	delete leds;
}

void Midi_Channel::loop()
{
	Animation::animations[program.old_value](this);


}

void Midi_Channel::map_leds(const int start, const int end)
{
	shadows.push_back({start, end, abs(end - start)});
}

void Midi_Channel::render(const fract8 alpha)
{
	for (shadow & shadow : shadows)
	{
		if (shadow.start < shadow.end) //forward
		{
			for (int i = 0; i < shadow.len; i++)
			{
				Light_Show::leds[shadow.start + i] = leds[i];
			}
		}
		else //backward
		{
			for (int i = 0; i < shadow.len; i++)
			{
				Light_Show::leds[shadow.start - i] = leds[i];
			}
		}
	}
}

void Midi_Channel::set_program(const byte new_program)
{
	old_program = program;
	program = new_program;

	fade_fract = 0;

	Tweener::
}

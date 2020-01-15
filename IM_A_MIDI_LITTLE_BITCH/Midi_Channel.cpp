#include "Midi_Channel.h"

extern CRGBArray<NUM_LEDS> gleds;

Midi_Channel::Midi_Channel()
{
	shadows.push_back({ 0, NUM_LEDS - 1, NUM_LEDS });
	animations.push_back(new Animation(my_leds));
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
	for (auto& shadow : shadows)
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
	vars.old_program = vars.program;
	vars.program = new_program;

	vars.fade_fract = 0;

	Tweener::tween(&vars.fade_fract, UINT16_MAX);
}

void Midi_Channel::note_off(byte note, byte velocity)
{
	vars.note_off.note = note;
	vars.note_off.velocity = velocity;
	vars.last_event = OFF;

	for (auto& animation : animations)
	{
		animation->ani_callback(OFF, note, velocity);
	}
}

void Midi_Channel::note_on(byte note, byte velocity)
{
	vars.note_on.note = note;
	vars.note_on.velocity = velocity;
	vars.last_event = ON;
	
	for (auto& animation : animations)
	{
		animation->ani_callback(ON, note, velocity);
	}
}

void Midi_Channel::after_touch_poly(byte note, byte pressure)
{
	vars.after_touch_poly.note = note;
	vars.after_touch_poly.pressure = pressure;
}

void Midi_Channel::control_change(byte number, byte value)
{
}

void Midi_Channel::program_change(byte number)
{
}

void Midi_Channel::after_touch_channel(byte pressure)
{
}

void Midi_Channel::pitch_bend(int bend)
{
}

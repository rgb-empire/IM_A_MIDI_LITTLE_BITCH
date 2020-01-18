#include "Midi_Channel.h"

Midi_Channel::Midi_Channel(int num_leds)
	:num_leds(num_leds),
	ch_leds(new CRGB[num_leds]),
	ch_led_set(CRGBSet(ch_leds, num_leds))
{
	animations.push_back(new Animation(ch_led_set));
}

Midi_Channel::~Midi_Channel()
{
	delete ch_leds;
}

void Midi_Channel::loop()
{
	render();
}

void Midi_Channel::map_leds(const int start, int len)
{
	START3;

	if (abs(len) > num_leds)
	{
		len = num_leds;
	}

	if (start + len > NUM_LEDS)
	{
		len = NUM_LEDS - start;
	}

	ch_pixel_maps.push_back(new Pixel_Map(ch_led_set(0, len - 1), gleds(start, start + len - 1)));

	END3;
}

void Midi_Channel::render(const fract8 alpha)
{
	START3;

	for (auto& pixel_map : ch_pixel_maps)
	{
		THING4;
		pixel_map->add_source_to_drain(alpha);
	}

	END3;
}

void Midi_Channel::set_program(const byte new_program)
{
	START2;
	P2(new_program);
	vars.old_program = vars.program;
	vars.program = new_program;

	vars.fade_fract = 0;

	Tweener::tween(&vars.fade_fract, UINT16_MAX);

	END2;
}

void Midi_Channel::note_off(byte note, byte velocity)
{
	START3;

	vars.note_off.note = note;
	vars.note_off.velocity = velocity;
	vars.last_event = OFF;

	for (auto& animation : animations)
	{
		THING4;
		animation->ani_callback(OFF, note, velocity);
	}

	END3;
}

void Midi_Channel::note_on(byte note, byte velocity)
{
	START3;

	vars.note_on.note = note;
	vars.note_on.velocity = velocity;
	vars.last_event = ON;
	
	for (auto& animation : animations)
	{
		THING4;
		animation->ani_callback(ON, note, velocity);
	}

	END3;
}

void Midi_Channel::after_touch_poly(byte note, byte pressure)
{
	START3;

	vars.after_touch_poly.note = note;
	vars.after_touch_poly.pressure = pressure;

	END3;
}

void Midi_Channel::control_change(byte number, byte value)
{
	START3;
	END3;
}

void Midi_Channel::program_change(byte number)
{
	START3;
	END3;
}

void Midi_Channel::after_touch_channel(byte pressure)
{
	START3;
	END3;
}

void Midi_Channel::pitch_bend(int bend)
{
	START3;
	END3;
}

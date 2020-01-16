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
	if (abs(len) > num_leds)
	{
		len = num_leds;
	}

	if (start + len > num_leds)
	{
		len = num_leds - start;
	}

	ch_pixel_maps.push_back(new Pixel_Map(ch_led_set(0, len - 1), gleds(start, start + len - 1)));
}

void Midi_Channel::render(const fract8 alpha)
{

	for (auto& pixel_map : ch_pixel_maps)
	{
		pixel_map->add_source_to_drain(alpha);
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

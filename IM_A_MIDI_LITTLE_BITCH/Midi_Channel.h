#pragma once

#include <vector>
#include "Fader.h"
#include "Animation.h"
#include "Light_Show.h"
#include "Tweener.h"

class Midi_Channel
{
protected:

	struct shadow {
		int start;
		int end;
		int len;
	};

	CRGBArray<NUM_LEDS> leds;
	
	std::vector<shadow> shadows;

	byte program;
	byte old_program;
	fract16 fade_fract;

	byte note_on_number;
	byte note_on_velocity;
	byte note_off_number;
	byte note_off_velocity;

	byte poly_aftertouch_number;
	byte poly_aftertouch_pressure;

	byte aftertouch_pressure;

	byte pitch_wheel_LSB;
	byte pitch_wheel_MSB;
	// Bit field for our 14-bit pitch wheel range
	unsigned char pitch_wheel_range : 14;

	// Control Changes
	// TODO: Put all control change instructions here maybe

public:
	Midi_Channel();
	~Midi_Channel();

	void loop();

	void map_leds(const int start, const int end);
	void render(const fract8 alpha = 0);

	void set_program(const byte new_program);
};


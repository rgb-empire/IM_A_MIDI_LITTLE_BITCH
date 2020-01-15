#pragma once

#include "Global_Definitions.h"

class Midi_Channel
{
protected:

	friend class Midi_Controller;
	friend class Animation_Controller;

	struct shadow {
		int start;
		int end;
		int len;
	};

	CRGBArray<NUM_LEDS> my_leds;
	
	std::vector<shadow> shadows;
	Animation* animation;

	byte program;
	byte old_program;
	int fade_fract;

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
	Event last_event;

	Midi_Channel();
	~Midi_Channel();

	void loop();

	void map_leds(const int start, const int end);
	void render(const fract16 alpha = 0);

	void set_program(const byte new_program);

protected:
	void noteOff(byte note, byte velocity);
	void noteOn(byte note, byte velocity);
	//void handleAfterTouchPoly(byte channel, byte note, byte pressure);
	//void handleControlChange(byte channel, byte number, byte value);
	//void handleProgramChange(byte channel, byte number);
	//void handleAfterTouchChannel(byte channel, byte pressure);
	//void handlePitchBend(byte channel, int bend);
	//void handleSystemExclusive(byte* array, unsigned size);
	//void handleTimeCodeQuarterFrame(byte data);
	//void handleSongPosition(unsigned int beats);
	//void handleSongSelect(byte songnumber);
	//void handleTuneRequest(void);
	//void handleClock(void);
	//void handleStart(void);
	//void handleContinue(void);
	//void handleStop(void);
	//void handleActiveSensing(void);
	//void handleSystemReset(void);

};


#pragma once

#include "Global_Definitions.h"

class Midi_Channel
{
protected:

	friend class Midi_Controller;
	friend class Animation_Controller;

	int num_leds;
	CRGB* ch_leds;
	CRGBSet ch_led_set;
	
	std::vector<Pixel_Map*> ch_pixel_maps;
	std::vector<Animation*> animations;

public:
	Channel_Vars vars;

	Midi_Channel(int num_leds);
	~Midi_Channel();

	void loop();

	void map_leds(const int start, const int len);
	void render(const fract8 alpha = 0);

	void set_program(const byte new_program);

protected:
	void note_off(byte note, byte velocity);
	void note_on(byte note, byte velocity);
	void after_touch_poly(byte note, byte pressure);
	void control_change(byte number, byte value);
	void program_change(byte number);
	void after_touch_channel(byte pressure);
	void pitch_bend(int bend);
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


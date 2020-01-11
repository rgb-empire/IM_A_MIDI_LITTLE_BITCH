#pragma once

#include <FastLED.h>
#include <vector>

#include "Midi_Channel.h"

#define G_NUM_LEDS 2304

class Light_Show
{
protected:
	
public:
	static int num_leds;
	static CRGBArray<G_NUM_LEDS> leds;

	static std::vector<Midi_Channel> channels;

	Light_Show();
	~Light_Show();

	void loop();
};


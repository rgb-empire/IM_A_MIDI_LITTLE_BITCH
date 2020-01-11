#pragma once

#include <FastLED.h>
#include <vector>

#define NUM_LEDS 2304

#include "Midi_Channel.h"
#include "Animation_Controller.h"

class Light_Show
{
protected:
	
public:
	static CRGBArray<NUM_LEDS> leds;

	static void init(int num_channels);

	static void loop();
};


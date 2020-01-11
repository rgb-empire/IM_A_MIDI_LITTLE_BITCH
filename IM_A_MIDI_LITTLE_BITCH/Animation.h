#pragma once

#include <FastLED.h>
#include "Midi_Channel.h"
#include "Details.h"

typedef void(*Animation_Func)(Midi_Channel channel);

class Animation
{
protected:
	//CRGBSet leds;

public:

	static Animation_Func animations[];

	Animation();
	~Animation();

	static void meteor(Midi_Channel channel);
};


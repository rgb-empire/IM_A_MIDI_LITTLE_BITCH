/*
 Name:		IM_A_MIDI_LITTLE_BITCH.ino
 Created:	1/8/2020 6:26:04 PM
 Author:	pikipupiba
*/

// the setup function runs once when you press reset or power the board
#include "Global_Definitions.h"

void setup()
{
	for (int i = 0; i < NUM_MIDI_CHANNELS; i++)
	{
		gchannels.push_back(new Midi_Channel());
		gcontrollers.push_back(new Animation_Controller(gchannels.back()));
	}

	FastLED.addLeds<NEOPIXEL, 21>(gleds, 0, NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 19>(gleds, NUM_LEDS / 8 + 1, NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 18>(gleds, 2 * (NUM_LEDS / 8) + 1, NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 15>(gleds, 3 * (NUM_LEDS / 8) + 1, NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 2>(gleds, 4 * (NUM_LEDS / 8) + 1, NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 0>(gleds, 5 * (NUM_LEDS / 8) + 1, NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 4>(gleds, 6 * (NUM_LEDS / 8) + 1, NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 5>(gleds, 7 * (NUM_LEDS / 8) + 1, NUM_LEDS / 8);
}

// the loop function runs over and over again until power down or reset
void loop()
{
	EVERY_N_SECONDS(2)
	{
		if (gchannels[0]->last_event == ON)
		{
			Midi_Controller::handleNoteOff(0, random8(), random8());
		}
		else
		{
			Midi_Controller::handleNoteOn(0, random8(), random8());
		}
	}

	gchannels[0]->render();

	FastLED.show();
}

/*
 Name:		IM_A_MIDI_LITTLE_BITCH.ino
 Created:	1/8/2020 6:26:04 PM
 Author:	pikipupiba
*/

// the setup function runs once when you press reset or power the board
#include "Global_Definitions.h"

//MIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
	delay(500);

	Serial.begin(115200);

	// Delay to allow uploader time to fix unstable software.
	// Reduce or remove this for production.
	delay(500);

	Midi_Controller::init();

	for (int i = 0; i < NUM_MIDI_CHANNELS; i++)
	{
		gchannels.push_back(new Midi_Channel());
		gcontrollers.push_back(new Animation_Controller(gchannels.back()));
	}

	FastLED.addLeds<NEOPIXEL, 21>(gleds, 0, NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 19>(gleds, NUM_LEDS / 8, NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 18>(gleds, 2 * (NUM_LEDS / 8), NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 15>(gleds, 3 * (NUM_LEDS / 8), NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 2>(gleds, 4 * (NUM_LEDS / 8), NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 0>(gleds, 5 * (NUM_LEDS / 8), NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 4>(gleds, 6 * (NUM_LEDS / 8), NUM_LEDS / 8);
	FastLED.addLeds<NEOPIXEL, 5>(gleds, 7 * (NUM_LEDS / 8), NUM_LEDS / 8);
}

int hue = 0;

// the loop function runs over and over again until power down or reset
void loop()
{
	Universe::loop();

	//MIDI.read();

	EVERY_N_SECONDS(5)
	{
		int new_hue = random8(128);

		printf("new_hue : %i\n", new_hue);
		printf("FPS : %i\n", FastLED.getFPS());

		Tweener::tween(&hue, new_hue);
	}

	EVERY_N_MILLISECONDS(400)
	{
		printf("hue : %i\n", hue);
	}

	Tweener::update();

	Midi_Controller::handleNoteOn(0, hue, 255);

	gchannels[0]->render();

	FastLED.show();

	FastLED.countFPS();
	
}

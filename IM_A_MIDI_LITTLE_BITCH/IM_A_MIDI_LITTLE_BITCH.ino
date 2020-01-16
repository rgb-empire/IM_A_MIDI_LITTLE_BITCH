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

	for (int i = 0; i < NUM_MIDI_CHANNELS / 2; i++)
	{
		gchannels.push_back(new Midi_Channel(Midi_Channel_Settings[i].len));

		gchannels.back()->map_leds(Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);

		switch (i)
		{
		case 0:
			FastLED.addLeds<NEOPIXEL, 21>(gleds, 0, Midi_Channel_Settings[i].len);
			break;
		case 1:
			FastLED.addLeds<NEOPIXEL, 19>(gleds, 0, Midi_Channel_Settings[i].len);
			break;
		case 2:
			FastLED.addLeds<NEOPIXEL, 18>(gleds, 0, Midi_Channel_Settings[i].len);
			break;
		case 3:
			FastLED.addLeds<NEOPIXEL, 15>(gleds, 0, Midi_Channel_Settings[i].len);
			break;
		case 4:
			FastLED.addLeds<NEOPIXEL, 2>(gleds, 0, Midi_Channel_Settings[i].len);
			break;
		case 5:
			FastLED.addLeds<NEOPIXEL, 0>(gleds, 0, Midi_Channel_Settings[i].len);
			break;
		case 6:
			FastLED.addLeds<NEOPIXEL, 4>(gleds, 0, Midi_Channel_Settings[i].len);
			break;
		case 7:
			FastLED.addLeds<NEOPIXEL, 5>(gleds, 0, Midi_Channel_Settings[i].len);
			break;
		}
	}
}

int hue = 0;

// the loop function runs over and over again until power down or reset
void loop()
{
	gleds.fill_solid(CRGB::Black);

	Universe::loop();

	//MIDI.read();

	EVERY_N_MILLISECONDS(Universe::beat_duration(8))
	{
		int new_hue = random8(128);

		printf("new_hue : %i\n", new_hue);
		printf("FPS : %i\n", FastLED.getFPS());

		Tweener::tween(&hue, new_hue, Universe::beat_duration(4));
	}

	//EVERY_N_MILLISECONDS(400)
	//{
	//	printf("hue : %i\n", hue);
	//}

	if (Universe::beat)
	{
		Serial.println("BEAT!");
	}

	Tweener::update();

	Midi_Controller::handleNoteOn(0, hue, 255);

	gchannels[0]->render();

	FastLED.show();

	FastLED.countFPS();
}

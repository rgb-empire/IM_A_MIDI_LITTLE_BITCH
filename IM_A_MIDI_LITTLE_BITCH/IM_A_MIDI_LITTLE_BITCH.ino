/*
 Name:		IM_A_MIDI_LITTLE_BITCH.ino
 Created:	1/8/2020 6:26:04 PM
 Author:	pikipupiba
*/

// the setup function runs once when you press reset or power the board
#include "arduino.h"
#include <bitset>
#include <vector>
#include <string>
#include <FastLED.h>
#include <MIDI.h>
#include <HardwareSerial.h>

#include "Global_Definitions.h"

HardwareSerial mySerial(1);
//HardwareSerial MIDI_SERIAL(0);

#include "Bug.h"

//MIDI_CREATE_INSTANCE(HardwareSerial, MIDI_SERIAL, MIDI);
MIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
	delay(500);


	Midi_Controller::init(MIDI);
	//MIDI.begin();

	delay(500);

	Serial.begin(115200);
	//MIDI_SERIAL.begin(115200);

	delay(500);

	mySerial.begin(115200, SERIAL_8N1, 26, 27);

	// Delay to allow uploader time to fix unstable software.
	// Reduce or remove this for production.
	delay(500);

	START1;

	for (int i = 0; i < 8; i++)
	{
		MEM2;

		gchannels.push_back(new Midi_Channel(Midi_Channel_Settings[i].len));

		gchannels.back()->map_leds(Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);

		switch (i)
		{
		case 0:
			FastLED.addLeds<NEOPIXEL, 21>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		case 1:
			FastLED.addLeds<NEOPIXEL, 19>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		case 2:
			FastLED.addLeds<NEOPIXEL, 18>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		case 3:
			FastLED.addLeds<NEOPIXEL, 15>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		case 4:
			FastLED.addLeds<NEOPIXEL, 2>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		case 5:
			FastLED.addLeds<NEOPIXEL, 25>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		case 6:
			FastLED.addLeds<NEOPIXEL, 4>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		case 7:
			FastLED.addLeds<NEOPIXEL, 5>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		}
	}

	END1;
}

int hue = 0;

// the loop function runs over and over again until power down or reset
void loop()
{
	START3;

	gleds.fill_solid(CRGB::Black);

	Universe::loop();

	if (MIDI.read())
	{
		mySerial.println("READING A THING");
	}

	EVERY_N_MILLISECONDS(2000)
	{
		static bool on = false;

		mySerial.println("WE DID IT");

		if (!on)
		{
			on = true;
			Midi_Controller::handleNoteOn(0, hue, 255);
		}
		else
		{
			on = false;
			Midi_Controller::handleNoteOff(0, hue, 255);
		}

		//MIDI.sendNoteOn(42, 127, 1);
	}

	Tweener::update();

	gchannels[0]->render();

	FastLED.show();
	
	FastLED.countFPS();

	END3;
}

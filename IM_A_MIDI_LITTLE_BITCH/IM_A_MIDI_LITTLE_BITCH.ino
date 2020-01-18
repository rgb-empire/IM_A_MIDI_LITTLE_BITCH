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
//#include <SoftwareSerial.h>

#include "Global_Definitions.h"

//HardwareSerial Serial(0);
//HardwareSerial MIDI_SERIAL(1);

#include "Bug.h"

//MIDI_CREATE_INSTANCE(HardwareSerial, MIDI_SERIAL, MIDI);

//SoftwareSerial Serial(33, 5);

void setup()
{
	delay(500);

	Serial.begin(115200);// , SERIAL_8N1, 3, 1);
	//Serial.begin(115200);
	//while (!Serial);

	// Delay to allow uploader time to fix unstable software.
	// Reduce or remove this for production.
	delay(500);

	START2;

	//MIDI.setHandleNoteOff(Midi_Controller::handleNoteOff);
	//MIDI.setHandleNoteOn(Midi_Controller::handleNoteOn);
	//MIDI.setHandleAfterTouchPoly(Midi_Controller::handleAfterTouchPoly);
	//MIDI.setHandleControlChange(Midi_Controller::handleControlChange);
	//MIDI.setHandleProgramChange(Midi_Controller::handleProgramChange);
	//MIDI.setHandleAfterTouchChannel(Midi_Controller::handleAfterTouchChannel);
	//MIDI.setHandlePitchBend(Midi_Controller::handlePitchBend);
	//MIDI.setHandleSystemExclusive(Midi_Controller::handleSystemExclusive);
	//MIDI.setHandleTimeCodeQuarterFrame(Midi_Controller::handleTimeCodeQuarterFrame);
	//MIDI.setHandleSongPosition(Midi_Controller::handleSongPosition);
	//MIDI.setHandleSongSelect(Midi_Controller::handleSongSelect);
	//MIDI.setHandleTuneRequest(Midi_Controller::handleTuneRequest);
	//MIDI.setHandleClock(Midi_Controller::handleClock);
	//MIDI.setHandleStart(Midi_Controller::handleStart);
	//MIDI.setHandleContinue(Midi_Controller::handleContinue);
	//MIDI.setHandleStop(Midi_Controller::handleStop);
	//MIDI.setHandleActiveSensing(Midi_Controller::handleActiveSensing);
	//MIDI.setHandleSystemReset(Midi_Controller::handleSystemReset);

	//Midi_Controller::init(MIDI);

	for (int i = 0; i < 8; i++)
	{
		MEM2;

		P2(i);

		gchannels.push_back(new Midi_Channel(Midi_Channel_Settings[i].len));

		THING2;

		gchannels.back()->map_leds(Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);

		P2(Midi_Channel_Settings[i].start);
		P2(Midi_Channel_Settings[i].len);

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
			FastLED.addLeds<NEOPIXEL, 0>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		case 6:
			FastLED.addLeds<NEOPIXEL, 4>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		case 7:
			FastLED.addLeds<NEOPIXEL, 5>(gleds, Midi_Channel_Settings[i].start, Midi_Channel_Settings[i].len);
			break;
		}
	}

	//MIDI.begin(MIDI_CHANNEL_OMNI);

	do
	{
		Serial.println("boooooooooooooobiesssssssss");
		delay(100);
	} while (true);

	END2;
}

int hue = 0;

// the loop function runs over and over again until power down or reset
void loop()
{
	START2;

	Serial.println("HMMMMMMMMMMMMMMMMMMMM");


	gleds.fill_solid(CRGB::Black);

	Universe::loop();

	//MIDI.read();

	EVERY_N_MILLISECONDS(Universe::beat_duration(8))
	{
		int new_hue = random8(128);

	//	//printf("new_hue : %i\n", new_hue);
	//	//printf("FPS : %i\n", FastLED.getFPS());

		Tweener::tween(&hue, new_hue, Universe::beat_duration(4));
	}

	EVERY_N_MILLISECONDS(400)
	{

		//Serial.printf("hue : %i\n", hue);

	}

	if (Universe::beat)
	{
		//Serial.println("BEAT!");
	}

	Tweener::update();

	//Midi_Controller::handleNoteOn(0, hue, 255);

	gchannels[0]->render();

	FastLED.show();
	
	FastLED.countFPS();

	START2;
}

/*
 Name:		IM_A_MIDI_LITTLE_BITCH.ino
 Created:	1/8/2020 6:26:04 PM
 Author:	pikipupiba
*/

#include "Global_Definitions.h"

struct MySettings : public midi::DefaultSettings
{
	static const bool Use1ByteParsing = false;
	static const long BaudRate = 256000;
	static const unsigned SysExMaxSize = 1024; // Accept SysEx messages up to 1024 bytes long.
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);

//MIDI_CREATE_DEFAULT_INSTANCE();

HardwareSerial mySerial(1);
//HardwareSerial MIDI_SERIAL(0);

void setup()
{
	delay(500);
	//Midi_Controller::init();
	delay(500);
	Serial.begin(256000);
	//MIDI_SERIAL.begin(115200);
	delay(500);
	mySerial.begin(115200, SERIAL_8N1, 26, 27);
	delay(500);

	START1;

	mySerial.println("Starting it up!");

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
	THING1;
	MIDI.setHandleNoteOff(Midi_Controller::handleNoteOff);
	THING1;
	MIDI.setHandleNoteOn(Midi_Controller::handleNoteOn);
	THING1;
	MIDI.setHandleAfterTouchPoly(Midi_Controller::handleAfterTouchPoly);
	THING1;
	MIDI.setHandleControlChange(Midi_Controller::handleControlChange);
	THING1;
	MIDI.setHandleProgramChange(Midi_Controller::handleProgramChange);
	THING1;
	MIDI.setHandleAfterTouchChannel(Midi_Controller::handleAfterTouchChannel);
	THING1;
	MIDI.setHandlePitchBend(Midi_Controller::handlePitchBend);
	THING1;
	MIDI.setHandleSystemExclusive(Midi_Controller::handleSystemExclusive);
	THING1;
	MIDI.setHandleTimeCodeQuarterFrame(Midi_Controller::handleTimeCodeQuarterFrame);
	THING1;
	MIDI.setHandleSongPosition(Midi_Controller::handleSongPosition);
	THING1;
	MIDI.setHandleSongSelect(Midi_Controller::handleSongSelect);
	THING1;
	MIDI.setHandleTuneRequest(Midi_Controller::handleTuneRequest);
	THING1;
	MIDI.setHandleClock(Midi_Controller::handleClock);
	THING1;
	MIDI.setHandleStart(Midi_Controller::handleStart);
	THING1;
	MIDI.setHandleContinue(Midi_Controller::handleContinue);
	THING1;
	MIDI.setHandleStop(Midi_Controller::handleStop);
	THING1;
	MIDI.setHandleActiveSensing(Midi_Controller::handleActiveSensing);
	THING1;
	MIDI.setHandleSystemReset(Midi_Controller::handleSystemReset);
	THING1;

	MIDI.begin(MIDI_CHANNEL_OMNI);
	MIDI.turnThruOff();

	END1;
}

void loop()
{
	//START3;

	mySerial.println("BUTTS THAT POOP");

	delay(10);

	gleds.fill_solid(CRGB::Black);

	Universe::loop();

	//Midi_Controller::loop();
	MIDI.read();
	
	Tweener::update();

	gchannels[0]->render();

	FastLED.show();
	
	FastLED.countFPS();

	//END3;
}
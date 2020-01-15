#pragma once

#include "Global_Definitions.h"

class Midi_Controller
{
public:
	static void init();

public:
	static void handleNoteOff(byte channel, byte note, byte velocity);
	static void handleNoteOn(byte channel, byte note, byte velocity);
	static void handleAfterTouchPoly(byte channel, byte note, byte pressure);
	static void handleControlChange(byte channel, byte number, byte value);
	static void handleProgramChange(byte channel, byte number);
	static void handleAfterTouchChannel(byte channel, byte pressure);
	static void handlePitchBend(byte channel, int bend);
	static void handleSystemExclusive(byte* array, unsigned size);
	static void handleTimeCodeQuarterFrame(byte data);
	static void handleSongPosition(unsigned int beats);
	static void handleSongSelect(byte songnumber);
	static void handleTuneRequest(void);
	static void handleClock(void);
	static void handleStart(void);
	static void handleContinue(void);
	static void handleStop(void);
	static void handleActiveSensing(void);
	static void handleSystemReset(void);
};


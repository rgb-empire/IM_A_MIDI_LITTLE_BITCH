#include "Midi_Controller.h"

void Midi_Controller::handleNoteOff(byte channel, byte note, byte velocity)
{
	gchannels[channel]->noteOff(note, velocity);
}

void Midi_Controller::handleNoteOn(byte channel, byte note, byte velocity)
{
	gchannels[channel]->noteOn(note, velocity);
}

void Midi_Controller::handleAfterTouchPoly(byte channel, byte note, byte pressure)
{
}

void Midi_Controller::handleControlChange(byte channel, byte number, byte value)
{
}

void Midi_Controller::handleProgramChange(byte channel, byte number)
{
}

void Midi_Controller::handleAfterTouchChannel(byte channel, byte pressure)
{
}

void Midi_Controller::handlePitchBend(byte channel, int bend)
{
}

void Midi_Controller::handleSystemExclusive(byte* array, unsigned size)
{
}

void Midi_Controller::handleTimeCodeQuarterFrame(byte data)
{
}

void Midi_Controller::handleSongPosition(unsigned int beats)
{
}

void Midi_Controller::handleSongSelect(byte songnumber)
{
}

void Midi_Controller::handleTuneRequest(void)
{
}

void Midi_Controller::handleClock(void)
{
}

void Midi_Controller::handleStart(void)
{
}

void Midi_Controller::handleContinue(void)
{
}

void Midi_Controller::handleStop(void)
{
}

void Midi_Controller::handleActiveSensing(void)
{
}

void Midi_Controller::handleSystemReset(void)
{
}

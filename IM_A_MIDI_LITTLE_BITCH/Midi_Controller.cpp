#include "Midi_Controller.h"

void Midi_Controller::init(midi::MidiInterface<HardwareSerial> &MIDI)
{
	MIDI.begin(MIDI_CHANNEL_OMNI);

	MIDI.setHandleNoteOff(handleNoteOff);
	MIDI.setHandleNoteOn(handleNoteOn);
	MIDI.setHandleAfterTouchPoly(handleAfterTouchPoly);
	MIDI.setHandleControlChange(handleControlChange);
	MIDI.setHandleProgramChange(handleProgramChange);
	MIDI.setHandleAfterTouchChannel(handleAfterTouchChannel);
	MIDI.setHandlePitchBend(handlePitchBend);
	MIDI.setHandleSystemExclusive(handleSystemExclusive);
	MIDI.setHandleTimeCodeQuarterFrame(handleTimeCodeQuarterFrame);
	MIDI.setHandleSongPosition(handleSongPosition);
	MIDI.setHandleSongSelect(handleSongSelect);
	MIDI.setHandleTuneRequest(handleTuneRequest);
	MIDI.setHandleClock(handleClock);
	MIDI.setHandleStart(handleStart);
	MIDI.setHandleContinue(handleContinue);
	MIDI.setHandleStop(handleStop);
	MIDI.setHandleActiveSensing(handleActiveSensing);
	MIDI.setHandleSystemReset(handleSystemReset);
}

void Midi_Controller::handleNoteOff(byte channel, byte note, byte velocity)
{
	gchannels[channel]->note_off(note, velocity);
}

void Midi_Controller::handleNoteOn(byte channel, byte note, byte velocity)
{
	gchannels[channel]->note_on(note, velocity);
}

void Midi_Controller::handleAfterTouchPoly(byte channel, byte note, byte pressure)
{
	gchannels[channel]->after_touch_poly(note, pressure);
}

void Midi_Controller::handleControlChange(byte channel, byte number, byte value)
{
	gchannels[channel]->control_change(number, value);
}

void Midi_Controller::handleProgramChange(byte channel, byte number)
{
	gchannels[channel]->program_change(number);
}

void Midi_Controller::handleAfterTouchChannel(byte channel, byte pressure)
{
	gchannels[channel]->after_touch_channel(pressure);
}

void Midi_Controller::handlePitchBend(byte channel, int bend)
{
	gchannels[channel]->pitch_bend(bend);
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

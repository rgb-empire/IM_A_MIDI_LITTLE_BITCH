#include "Midi_Controller.h"

//MIDI_CREATE_DEFAULT_INSTANCE();

void Midi_Controller::init()
{
	//MIDI.setHandleNoteOff(handleNoteOff);
	//MIDI.setHandleNoteOn(handleNoteOn);
	//MIDI.setHandleAfterTouchPoly(handleAfterTouchPoly);
	//MIDI.setHandleControlChange(handleControlChange);
	//MIDI.setHandleProgramChange(handleProgramChange);
	//MIDI.setHandleAfterTouchChannel(handleAfterTouchChannel);
	//MIDI.setHandlePitchBend(handlePitchBend);
	//MIDI.setHandleSystemExclusive(handleSystemExclusive);
	//MIDI.setHandleTimeCodeQuarterFrame(handleTimeCodeQuarterFrame);
	//MIDI.setHandleSongPosition(handleSongPosition);
	//MIDI.setHandleSongSelect(handleSongSelect);
	//MIDI.setHandleTuneRequest(handleTuneRequest);
	//MIDI.setHandleClock(handleClock);
	//MIDI.setHandleStart(handleStart);
	//MIDI.setHandleContinue(handleContinue);
	//MIDI.setHandleStop(handleStop);
	//MIDI.setHandleActiveSensing(handleActiveSensing);
	//MIDI.setHandleSystemReset(handleSystemReset);

	//MIDI.begin(MIDI_CHANNEL_OMNI);
}

void Midi_Controller::loop()
{
	//MIDI.read();
}

void Midi_Controller::handleNoteOff(byte channel, byte note, byte velocity)
{
	START2;
	//gchannels[channel]->note_off(note, velocity);
	END2;
}

void Midi_Controller::handleNoteOn(byte channel, byte note, byte velocity)
{
	START2;
	//gchannels[channel]->note_on(note, velocity);
	END2;
}

void Midi_Controller::handleAfterTouchPoly(byte channel, byte note, byte pressure)
{
	START2;
	gchannels[channel]->after_touch_poly(note, pressure);
	END2;
}

void Midi_Controller::handleControlChange(byte channel, byte number, byte value)
{
	START2;
	gchannels[channel]->control_change(number, value);
	END2;
}

void Midi_Controller::handleProgramChange(byte channel, byte number)
{
	START2;
	gchannels[channel]->program_change(number);
	END2;
}

void Midi_Controller::handleAfterTouchChannel(byte channel, byte pressure)
{
	START2;
	gchannels[channel]->after_touch_channel(pressure);
	END2;
}

void Midi_Controller::handlePitchBend(byte channel, int bend)
{
	START2;
	gchannels[channel]->pitch_bend(bend);
	END2;
}

void Midi_Controller::handleSystemExclusive(byte* array, unsigned size)
{
	START2;
	END2;
}

void Midi_Controller::handleTimeCodeQuarterFrame(byte data)
{
	START2;
	END2;
}

void Midi_Controller::handleSongPosition(unsigned int beats)
{
	START2;
	END2;
}

void Midi_Controller::handleSongSelect(byte songnumber)
{
	START2;
	END2;
}

void Midi_Controller::handleTuneRequest(void)
{
	START2;
	END2;
}

void Midi_Controller::handleClock(void)
{
	START2;
	END2;
}

void Midi_Controller::handleStart(void)
{
	START2;
	END2;
}

void Midi_Controller::handleContinue(void)
{
	START2;
	END2;
}

void Midi_Controller::handleStop(void)
{
	START2;
	END2;
}

void Midi_Controller::handleActiveSensing(void)
{
	START2;
	END2;
}

void Midi_Controller::handleSystemReset(void)
{
	START2;
	END2;
}

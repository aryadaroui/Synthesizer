/*
  ==============================================================================

    SynthVoice.h
    Created: 16 Feb 2019 11:12:49pm
    Author:  Arya Daroui

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../dependencies/maximilian/maximilian.h"
#include "SynthSound.h"

class SynthVoice : public SynthesiserVoice
{
public:
	bool canPlaySound(SynthesiserSound* sound)
	{
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}
	
	void startNote (int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchwheelPosition)
	{
        level = .5;
		frequency  = MidiMessage::getMidiNoteInHertz(midiNoteNumber); // gets the midi note and converts it to the frequency in Hz it should be
        
//        std::cout << "key: " <<  midiNoteNumber << " at "  << frequency << " Hz." <<  std::endl; // for debug
	}
	
	void stopNote (float velocity, bool allowTailOff)
	{
        level = 0;
		clearCurrentNote();
	}
	
	void pitchWheelMoved (int newPitchWheelValue)
	{
		
	}
	
	void controllerMoved (int controllerNumber, int newControllerValue)
	{
		
	}

	void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{
        double theWave;
        
        for (int sample = 0; sample < numSamples; ++sample)
        {
            theWave = car.triangle(frequency) * level;
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++ channel)
            {
                
                outputBuffer.addSample(channel, startSample, theWave);
            }
            ++startSample;
        }
	}

private:
	double level;
	double frequency;
    maxiOsc car; // carrier wave
    maxiOsc LFO; // LFO wave
};

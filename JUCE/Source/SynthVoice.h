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
	
	//======================================================================================
	void startNote (int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchwheelPosition)
	{
        level = .5;
		frequency  = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        std::cout << "key: " <<  midiNoteNumber << " at "  << frequency << " Hz." <<  std::endl;
		
	}
	
	void stopNote (float velocity, bool allowTailOff)
	{
        level = 0;
		clearCurrentNote();
	}
	
	//=======================================================================================
	void pitchWheelMoved (int newPitchWheelValue)
	{
		
	}
	
	void controllerMoved (int controllerNumber, int newControllerValue)
	{
		
	}

	void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{
		// TO DO: Windows Distribution off by 30Hz at 440Hz (A4). Error is multiplicative with octave.
        double theWave;
		double theSound; // For compatibility with ADSR
		theSound = theWave;
		double filteredSound;
//        std::cout << "rendering block" << std::endl;
        
        for (int sample = 0; sample < numSamples; ++sample)
        {
            theWave = car.sinewave(frequency) * level;
			//filteredSound = filter1.lores(theSound, 2000, 0.1); //low pass filter at 400Hz
			filteredSound = theWave;
            
			for (int channel = 0; channel < outputBuffer.getNumChannels(); ++ channel)
            {
				
                outputBuffer.addSample(channel, startSample, filteredSound);
            }
            ++startSample;
        }
	}

private:
	double level;
	double frequency;
    maxiOsc car;
    maxiOsc LFO;
	maxiFilter filter1; // Test Filter
};

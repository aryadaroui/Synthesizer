/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../dependencies/maximilian/maximilian.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SynthboyAudioProcessorEditor : public AudioProcessorEditor, public Slider::Listener
{
public:
    SynthboyAudioProcessorEditor (SynthboyAudioProcessor&);
    ~SynthboyAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthboyAudioProcessor& processor;
    
    Slider attack;
    Slider decay;
    Slider sustain;
    Slider release;

    Slider LowCutFrequency;
    Slider LowCutDepth;
    Slider HighCutFrequency;
    Slider HighCutDepth;

    Slider carShape;
    Slider lfoShape;
    Slider lfoFrequency;
    Slider lfoAttack;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthboyAudioProcessorEditor)
};

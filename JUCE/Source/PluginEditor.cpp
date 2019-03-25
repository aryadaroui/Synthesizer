/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthboyAudioProcessorEditor::SynthboyAudioProcessorEditor (SynthboyAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    lfoFrequency.setSliderStyle(Slider::SliderStyle::Rotary);
    lfoFrequency.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
//    lfoShape.setSliderStyle(Slider::SliderStyle::Rotary);
//    lfoAttack.setSliderStyle(Slider::SliderStyle::Rotary);
    addAndMakeVisible(lfoFrequency);
    setSize (400, 300);
}

SynthboyAudioProcessorEditor::~SynthboyAudioProcessorEditor()
{
}

//==============================================================================
void SynthboyAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void SynthboyAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    lfoFrequency.setBounds(getLocalBounds());
}

void SynthboyAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    
}

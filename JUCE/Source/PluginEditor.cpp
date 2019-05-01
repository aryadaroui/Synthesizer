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
	// LoCutFreq
	{
		addAndMakeVisible(LoCutFreq);
		LoCutFreq.setSliderStyle(Slider::SliderStyle::Rotary);
		LoCutFreq.setPopupDisplayEnabled(true, true, this);
		LoCutFreq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		LoCutFreq.setRange(10, 1000);
		LoCutFreq.setValue(500);
		LoCutFreq.setNumDecimalPlacesToDisplay(2);
		LoCutFreq.setTextValueSuffix(" Hz");
		LoCutFreq.addListener(this);
	}
	
	// LoCutDepth
	{
		addAndMakeVisible(LoCutDepth);
		LoCutDepth.setSliderStyle(Slider::SliderStyle::Rotary);
		LoCutDepth.setPopupDisplayEnabled(true, true, this);
		LoCutDepth.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		LoCutDepth.setRange(0, 100);
		LoCutDepth.setValue(50);
		LoCutDepth.setNumDecimalPlacesToDisplay(2);
		LoCutDepth.setTextValueSuffix("%");
		LoCutDepth.addListener(this);
	}
	
	// HiCutFreq
	{
		addAndMakeVisible(HiCutFreq);
		HiCutFreq.setSliderStyle(Slider::SliderStyle::Rotary);
		HiCutFreq.setPopupDisplayEnabled(true, true, this);
		HiCutFreq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		HiCutFreq.setRange(2, 20);
		HiCutFreq.setValue(10);
		HiCutFreq.setNumDecimalPlacesToDisplay(2);
		HiCutFreq.setTextValueSuffix(" kHz");
		HiCutFreq.addListener(this);
	}
	
	// HiCutDepth
	{
		addAndMakeVisible(HiCutDepth);
		HiCutDepth.setSliderStyle(Slider::SliderStyle::Rotary);
		HiCutDepth.setPopupDisplayEnabled(true, true, this);
		HiCutDepth.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		HiCutDepth.setRange(0, 100);
		HiCutDepth.setValue(50);
		HiCutDepth.setNumDecimalPlacesToDisplay(2);
		HiCutDepth.setTextValueSuffix("%");
		HiCutDepth.addListener(this);
	}
	
	// attack
	{
		addAndMakeVisible(attack);
		attack.setSliderStyle(Slider::SliderStyle::Rotary);
		attack.setPopupDisplayEnabled(true, true, this);
		attack.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		attack.setRange(.001, 10);
		attack.setValue(3);
		attack.setNumDecimalPlacesToDisplay(2);
		attack.setTextValueSuffix(" s");
		attack.addListener(this);
	}
	
	// decay
	{
		addAndMakeVisible(decay);
		decay.setSliderStyle(Slider::SliderStyle::Rotary);
		decay.setPopupDisplayEnabled(true, true, this);
		decay.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		decay.setRange(.001, 10);
		decay.setValue(5);
		decay.setNumDecimalPlacesToDisplay(2);
		decay.setTextValueSuffix(" s");
		decay.addListener(this);
	}
	
	// sustain
	{
		addAndMakeVisible(sustain);
		sustain.setSliderStyle(Slider::SliderStyle::Rotary);
		sustain.setPopupDisplayEnabled(true, true, this);
		sustain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		sustain.setRange(.001, 10);
		sustain.setValue(7);
		sustain.setNumDecimalPlacesToDisplay(2);
		sustain.setTextValueSuffix(" s");
		sustain.addListener(this);
	}
	
	// release
	{
		addAndMakeVisible(release);
		release.setSliderStyle(Slider::SliderStyle::Rotary);
		release.setPopupDisplayEnabled(true, true, this);
		release.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		release.setRange(.001, 10);
		release.setValue(10);
		release.setNumDecimalPlacesToDisplay(2);
		release.setTextValueSuffix(" s");
		release.addListener(this);
	}
	
	// lfoShape
	{
		addAndMakeVisible(lfoShape);
		lfoShape.setSliderStyle(Slider::SliderStyle::Rotary);
		lfoShape.setVelocityBasedMode(false);
		lfoShape.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		lfoShape.setRange(PULSE, RAMP, 1);
		lfoShape.setValue(SINE);
		lfoShape.addListener(this);
	}
	
	// lfoBlend
	{
		addAndMakeVisible(lfoBlend);
		lfoBlend.setSliderStyle(Slider::SliderStyle::Rotary);
		lfoBlend.setPopupDisplayEnabled(true, true, this);
		lfoBlend.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		lfoBlend.setRange(0, 100);
		lfoBlend.setValue(10);
		lfoBlend.setNumDecimalPlacesToDisplay(2);
		lfoBlend.setTextValueSuffix("%");
		lfoBlend.addListener(this);
	}
	
	// lfoFreq
	{
		addAndMakeVisible(lfoFreq);
		lfoFreq.setSliderStyle(Slider::SliderStyle::Rotary);
		lfoFreq.setPopupDisplayEnabled(true, true, this);
		lfoFreq.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		lfoFreq.setRange(0.1, 10);
		lfoFreq.setValue(1);
		lfoFreq.setNumDecimalPlacesToDisplay(2);
		lfoFreq.setTextValueSuffix(" Hz");
		lfoFreq.addListener(this);
	}
	
	// lfoCreep
	{
		addAndMakeVisible(lfoCreep);
		lfoCreep.setSliderStyle(Slider::SliderStyle::Rotary);
		lfoCreep.setPopupDisplayEnabled(true, true, this);
		lfoCreep.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		lfoCreep.setRange(.001, 10);
		lfoCreep.setValue(1);
		lfoCreep.setNumDecimalPlacesToDisplay(2);
		lfoCreep.setTextValueSuffix(" s");
		lfoCreep.addListener(this);
	}
	
	// carShape
	{
		addAndMakeVisible(carShape);
		carShape.setSliderStyle(Slider::SliderStyle::Rotary);
		carShape.setVelocityBasedMode(false);
		carShape.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		carShape.setRange(PULSE, RAMP, 1);
		carShape.setValue(SINE);
		carShape.addListener(this);
	}
	
	// carLevel
	{
		addAndMakeVisible(carLevel);
		carLevel.setSliderStyle(Slider::SliderStyle::Rotary);
		carLevel.setPopupDisplayEnabled(true, true, this);
		carLevel.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
		carLevel.setRange(0, 100);
		carLevel.setValue(90);
		carLevel.setNumDecimalPlacesToDisplay(2);
		carLevel.setTextValueSuffix("%");
		carLevel.addListener(this);
	}
	
    setSize (540, 650);
}

SynthboyAudioProcessorEditor::~SynthboyAudioProcessorEditor()
{
}

//==============================================================================
void SynthboyAudioProcessorEditor::paint (Graphics& g)
{
	Image background = ImageCache::getFromMemory(BinaryData::synthboy_UI_png, BinaryData::synthboy_UI_pngSize);
	g.drawImage(background, 0, 0, 540, 650, 0, 0, 540*2, 650*2);
	
//	g.fillAll (Colour(251, 134, 181));
	g.setColour(Colours::white);
	g.setFont (15.0f);
	getLookAndFeel().setColour(Slider::thumbColourId, Colours::white);
//	getLookAndFeel().setColour(Slider::textBoxOutlineColourId, Colours::white);
//    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
	

}

void SynthboyAudioProcessorEditor::resized()
{
	int size = 100;
	
	LoCutFreq.setBounds(40, 30, size, size);
	LoCutDepth.setBounds(160, 30, size, size);
	HiCutFreq.setBounds(280, 30, size, size);
	HiCutDepth.setBounds(400, 30, size, size);

	attack.setBounds(40, 190, size, size);
	decay.setBounds(160, 190, size, size);
	sustain.setBounds(280, 190, size, size);
	release.setBounds(400, 190, size, size);

	lfoShape.setBounds(40, 350, size, size);;
	lfoBlend.setBounds(160, 350, size, size);;
	lfoFreq.setBounds(280, 350, size, size);
	lfoCreep.setBounds(400, 350, size, size);;
	
	carShape.setBounds(40, 510, size, size);
	carLevel.setBounds(160, 510, size, size);;
	
}

void SynthboyAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
	if (slider == &lfoFreq) {
		processor.lfoFreq = lfoFreq.getValue();
	}
}

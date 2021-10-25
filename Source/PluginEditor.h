/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BaoGainAudioProcessorEditor  : public juce::AudioProcessorEditor, juce::Slider::Listener
{
public:
    BaoGainAudioProcessorEditor (BaoGainAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~BaoGainAudioProcessorEditor() override;

    void sliderValueChanged(juce::Slider* slider) override;


    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BaoGainAudioProcessor& audioProcessor;

    juce::Label levelLabel;
    juce::Slider levelSlider;

    juce::Label blurbLabel;

    juce::Label versionLabel;

    juce::AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> levelAttachment;
    
    // images
    juce::Image vince1;
    juce::Image vince2;
    juce::Image vince3;
    juce::Image vince4;
    juce::Image vince5;
    std::unique_ptr<juce::Image> chosenVince;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaoGainAudioProcessorEditor)
};

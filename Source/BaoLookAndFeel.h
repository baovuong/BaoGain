/*
  ==============================================================================

    BaoLookAndFeel.h
    Created: 26 Oct 2021 4:49:42pm
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class BaoLookAndFeel : public juce::LookAndFeel_V4
{
public:
    BaoLookAndFeel();
    void drawLinearSlider (
        juce::Graphics &, 
        int x, 
        int y, 
        int width, 
        int height, 
        float sliderPos, 
        float minSliderPos, 
        float maxSliderPos, 
        const juce::Slider::SliderStyle sliderStyle, 
        juce::Slider &slider);
    
    void drawLinearSliderThumb	(	
        juce::Graphics &,
        int 	x,
        int 	y,
        int 	width,
        int 	height,
        float 	sliderPos,
        float 	minSliderPos,
        float 	maxSliderPos,
        const juce::Slider::SliderStyle,
        juce::Slider & 	 
    );	
    
    void drawLinearSliderBackground	(	
        juce::Graphics &,
        int 	x,
        int 	y,
        int 	width,
        int 	height,
        float 	sliderPos,
        float 	minSliderPos,
        float 	maxSliderPos,
        const juce::Slider::SliderStyle,
        juce::Slider & 	 
    );	
};
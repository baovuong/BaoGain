/*
  ==============================================================================

    BaoLookAndFeel.cpp
    Created: 26 Oct 2021 4:49:42pm
    Author:  bvuong

  ==============================================================================
*/

#include "BaoLookAndFeel.h"

BaoLookAndFeel::BaoLookAndFeel()
{
    setColour(juce::Slider::thumbColourId, juce::Colours::green);
}

void BaoLookAndFeel::drawLinearSlider (
    juce::Graphics &g, 
    int x, 
    int y, 
    int width, 
    int height, 
    float sliderPos, 
    float minSliderPos, 
    float maxSliderPos, 
    const juce::Slider::SliderStyle sliderStyle, 
    juce::Slider &slider)
{
    // TODO implement this
    // thick vertical line with a ball on the top
    g.setColour(juce::Colours::white);
    g.drawLine(x, y, x, y+height, width);
}

void BaoLookAndFeel::drawLinearSliderThumb(
    juce::Graphics & 	,
    int 	x,
    int 	y,
    int 	width,
    int 	height,
    float 	sliderPos,
    float 	minSliderPos,
    float 	maxSliderPos,
    const juce::Slider::SliderStyle style,
    juce::Slider &slider 
    )	
{
    // TODO implement this
}
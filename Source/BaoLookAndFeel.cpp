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
    setColour(juce::Slider::backgroundColourId, juce::Colours::grey);
}

void BaoLookAndFeel::drawLinearSlider(
    juce::Graphics &g,
    int x,
    int y,
    int width,
    int height,
    float sliderPos,
    float minSliderPos,
    float maxSliderPos,
    const juce::Slider::SliderStyle style,
    juce::Slider &slider)
{
    // thick vertical line with a ball on the top
    g.fillAll(slider.findColour(juce::Slider::backgroundColourId));

    if (style == juce::Slider::LinearBar ||
        style == juce::Slider::LinearBarVertical)
    {
        LookAndFeel_V4::drawLinearSlider(g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
    }
    else
    {
        drawLinearSliderBackground(g, x, y, width,
                                   height, sliderPos, minSliderPos,
                                   maxSliderPos, style, slider);
        drawLinearSliderThumb(g, x, y, width,
                              height, sliderPos, minSliderPos,
                              maxSliderPos, style, slider);
    }
}

void BaoLookAndFeel::drawLinearSliderBackground(
    juce::Graphics &g,
    int x,
    int y,
    int width,
    int height,
    float sliderPos,
    float minSliderPos,
    float maxSliderPos,
    const juce::Slider::SliderStyle style,
    juce::Slider &slider)
{

    int halfWidth = width/2;
    g.setColour(juce::Colours::black);
    g.drawLine(halfWidth, y, halfWidth, height+y, 2);
    g.drawLine(halfWidth-10, y, halfWidth+10, y);
    g.drawLine(halfWidth-10, height+y, halfWidth+10, height+y);

    // horizontal lines
    int distance = height/5;
    for (int i=1; i<=4; i++) 
    {
        g.drawLine(halfWidth-5, y + distance*i, halfWidth+5, y + distance*i);
    }
}

void BaoLookAndFeel::drawLinearSliderThumb(
    juce::Graphics &g,
    int x,
    int y,
    int width,
    int height,
    float sliderPos,
    float minSliderPos,
    float maxSliderPos,
    const juce::Slider::SliderStyle style,
    juce::Slider &slider)
{
    int kx, ky;

    if (style == juce::Slider::LinearVertical)
    {
        kx = width/2;
        ky = sliderPos+1;
    }
    else
    {
        kx = sliderPos+1;
        ky = height/2;
    }

    g.setColour(slider.findColour(juce::Slider::thumbColourId));
    g.fillRect(kx-width/2, ky-10, width, 20);
}
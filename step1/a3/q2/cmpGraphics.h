#ifndef __CMPGRAPHICS_H__
#define __CMPGRAPHICS_H__

#include "rgbProcessor.h"

class HexaDecimal;
class ComputerGraphics : public RgbProcessor
{
    int width, height;

public:
    ComputerGraphics(int width, int height, ColourManager *c);
    Colour getColour(Input *rgb) override;
    RGB getRgb(Colour name) override;
    int getBrightness(Input *rgb) override;
    bool isValid(Input *rgb) override;
    HexaDecimal *convertToHex(Input *rgb) override;
};

#endif

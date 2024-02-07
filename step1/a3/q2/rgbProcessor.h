#ifndef __RGBPROCESSOR_H__
#define __RGBPROCESSOR_H__
// #include "rgb.h"
#include <map>
#include <exception>
#include <iostream>
enum class Colour
{
    Red,
    Green,
    Blue,
    Black,
    White,
    Yellow,
    Magenta,
    Cyan,
    Unknown
};

class Input;
struct RGB;
class HexaDecimal;

class ColourManager
{
    std::map<Colour, RGB> colToRgbMap;
    std::map<int, Colour> rgbToColMap;

    struct RGBPower
    {
        int third, second, first;
    };

    int generateRGBKey(RGB rgb);
    int convertDigit(RGBPower p, int colour);

public:
    ColourManager();
    Colour getColour(RGB rgb);
    RGB getRGB(Colour colour);
};

std::ostream &operator<<(std::ostream &out, Colour c);

class RgbProcessor
{
protected:
    ColourManager *colourManager;

public:
    RgbProcessor(ColourManager *c);
    ~RgbProcessor();
    virtual Colour getColour(Input *rgb) = 0;
    virtual RGB getRgb(Colour name) = 0;
    virtual int getBrightness(Input *rgb) = 0;
    virtual bool isValid(Input *rgb) = 0;
    virtual HexaDecimal *convertToHex(Input *rgb) = 0;
};

/*
1st 어떤 데이터를 manipulate하는가? +
    이 데이터를 manipulate하는데 어떤 data structure가 필요로 하는가?

*/

#endif

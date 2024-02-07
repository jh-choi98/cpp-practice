#include "cmpGraphics.h"
#include "rgb.h"
#include "input.h"
#include <map>
#include <vector>

using namespace std;

ComputerGraphics::ComputerGraphics(int width, int height, ColourManager *c)
    : RgbProcessor{c}, width{width}, height{height}
{
}

// Colour findKeyByValue(RGB rgbValue)
// {
//     ColourManager colourManager;
//     map<Colour, RGB> rgbMap = colourManager.rgbMap;
//     for (auto it = rgbMap.begin(); it != rgbMap.end(); ++it)
//     {
//         if (it->second == rgbValue)
//         {
//             return it->first;
//         }
//         return Colour::Unknown;
//     }
// }

Colour ComputerGraphics::getColour(Input *rgb)
{
    return colourManager->getColour(rgb->getRgb());
}

RGB ComputerGraphics::getRgb(Colour name)
{
    return colourManager->getRGB(name);
}

int ComputerGraphics::getBrightness(Input *rgb)
{
    auto [r, g, b] = rgb->getRgb();
    return r * 0.3 + g * 0.59 + b * 0.11;
}

bool ComputerGraphics::isValid(Input *rgb)
{
    return rgb->isValid();
}

HexaDecimal *ComputerGraphics::convertToHex(Input *rgb)
{
}

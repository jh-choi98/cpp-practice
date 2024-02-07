#include "rgbProcessor.h"
#include "rgb.h"
#include <cmath>

RgbProcessor::RgbProcessor(ColourManager *c) : colourManager{c} {}

RgbProcessor::~RgbProcessor()
{
    delete colourManager;
}
ColourManager::ColourManager()
{
    const int NUM_COLOURS = 8;
    RGB rgbs[] = {
        RGB::RED(),
        RGB::GREEN(),
        RGB::BLUE(),
        RGB::BLACK(),
        RGB::WHITE(),
        RGB::YELLOW(),
        RGB::MAGENTA(),
        RGB::CYAN()};

    Colour colours[] = {
        Colour::Red,
        Colour::Green,
        Colour::Blue,
        Colour::Black,
        Colour::White,
        Colour::Yellow,
        Colour::Magenta,
        Colour::Cyan};

    for (int i = 0; i < NUM_COLOURS; i++)
    {
        colToRgbMap[colours[i]] = rgbs[i];
    }

    for (int i = 0; i < NUM_COLOURS; i++)
    {
        rgbToColMap[generateRGBKey(rgbs[i])] = colours[i];
    }
}

int ColourManager::convertDigit(RGBPower p, int colour)
{
    // colour => 5, 45, 188
    int digits[3] = {0, 0, 0};
    int d = 1;
    if (colour >= 10)
    {
        d++;
    }

    if (colour >= 100)
    {
        d++;
    }

    int number = colour;
    for (int i = 0; i < d; i++)
    {
        digits[i] = number % 10;
        number /= 10;
    }

    return p.first * digits[0] + p.second * digits[1] + p.third * digits[2];
}

int ColourManager::generateRGBKey(RGB rgb)
{
    RGBPower R = {pow(10, 8), pow(10, 7), pow(10, 6)},
             G = {pow(10, 5), pow(10, 4), pow(10, 3)},
             B = {pow(10, 2), pow(10, 1), pow(10, 0)};

    return convertDigit(R, rgb.r) + convertDigit(G, rgb.g) + convertDigit(B, rgb.b);
}

Colour ColourManager::getColour(RGB rgb)
{
    // 10^8 + 10^7 + 10^6 + 10^5 + 10^4 + 10^3 + 10^2 + 10^1 + 10^0
    try
    {
        int key = generateRGBKey(rgb);
        Colour colour = rgbToColMap.at(key); // ***************
        return colour;
    }
    catch (std::exception &e)
    {
        return Colour::Unknown;
    }
}
RGB ColourManager::getRGB(Colour colour)
{
    try
    {
        RGB rgb = colToRgbMap.at(colour);
        return rgb;
    }
    catch (std::exception &e)
    {
        return RGB::UNKNOWN();
    }
}

std::ostream &operator<<(std::ostream &out, Colour c)
{
    if (c == Colour::Red)
    {
        out << "Red" << std::endl;
    }
    else if (c == Colour::Green)
    {
        out << "Green" << std::endl;
    }
    else if (c == Colour::Black)
    {
        out << "Black" << std::endl;
    }
    else if (c == Colour::Blue)
    {
        out << "Blue" << std::endl;
    }
    else if (c == Colour::Magenta)
    {
        out << "Mageta" << std::endl;
    }
    else if (c == Colour::Cyan)
    {
        out << "Cyan" << std::endl;
    }
    else if (c == Colour::Yellow)
    {
        out << "Yello" << std::endl;
    }
    else if (c == Colour::White)
    {
        out << "White" << std::endl;
    }
    else
    {
        out << "Unknown" << std::endl;
    }
    return out;
}

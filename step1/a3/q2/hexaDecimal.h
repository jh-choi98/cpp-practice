#ifndef __HEXADECIMAL_H__
#define __HEXADECIMAL_H__

#include "rgb.h"

class HexaDecimal
{
public:
    virtual HexaDecimal *getHex(RGB rgb) = 0;
    virtual ~HexaDecimal();
};

#endif

// To make output flexible

#ifndef __STATEVALUE_H__
#define __STATEVALUE_H__

#include "enum.h"
#include <iostream>

struct StateValue
{
    int x, y;
    Direction dir;
};

std::ostream &operator<<(std::ostream &out, StateValue st);

#endif

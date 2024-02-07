#ifndef __ENUM_H__
#define __ENUM_H__

#include <iostream>

enum class Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

enum class CMD
{
    Forward,
    TurnLeft,
    TurnRight
};

std::ostream &operator<<(std::ostream &out, Direction dir);

#endif

#include "enum.h"

std::ostream &operator<<(std::ostream &out, Direction dir)
{
    if (dir == Direction::NORTH)
    {
        out << "North";
    }
    else if (dir == Direction::SOUTH)
    {
        out << "South";
    }
    else if (dir == Direction::EAST)
    {
        out << "East";
    }
    else
    {
        out << "West";
    }
    return out;
}

#include "rgb.h"
#include <map>

using std::map;

bool RGB::operator==(const RGB &other) const
{
    return r == other.r && g == other.g && b == other.b;
}

bool RGB::operator<(const RGB &other) const
{
    return !operator==(other);
}

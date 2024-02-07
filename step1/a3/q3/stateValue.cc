#include "stateValue.h"

std::ostream &operator<<(std::ostream &out, StateValue st)
{
    out << "[ x: " << st.x << ", y: " << st.y << ", Direction: " << st.dir << " ]" << std::endl;
    return out;
}

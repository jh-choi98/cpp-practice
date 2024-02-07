#ifndef __STATE_H__
#define __STATE_H__

#include "stateValue.h"
#include <memory>

class State
{
public:
    virtual StateValue getStateValue() = 0;
    virtual unique_ptr<State> getNewState(int x, int y, Direction dir) = 0;
    virtual ~State();
};

#endif

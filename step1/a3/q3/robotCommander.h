#ifndef __ROBOTCOMMANDER_H__
#define __ROBOTCOMMANDER_H__

#include "state.h"
#include "stateValue.h"
#include "node.h"
#include "enum.h"

class RobotCommander
{
    State *robotControl(State *st, CMD cmd);
};

#endif

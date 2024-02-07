#include "robotCommander.h"

State *RobotCommander::robotControl(State *st, CMD cmd)
{
    const int NUM_DIRECTIONS = 4;
    int index = 0;

    Direction directions[] = {
        Direction::NORTH,
        Direction::EAST,
        Direction::SOUTH,
        Direction::WEST,
    };
    StateValue stValue = st->getStateValue();
    Direction dir = stValue.dir;
    int x = stValue.x;
    int y = stValue.y;

    for (int i = 0; i < NUM_DIRECTIONS; i++)
    {
        if (dir == directions[i])
        {
            index = i;
        }
    }

    if (cmd == CMD::TurnRight)
    {
        ++index;
        if (index > 3)
        {
            index = 0;
        }
        dir = directions[index];
    }
    else if (cmd == CMD::TurnLeft)
    {
        --index;
        if (index < 0)
        {
            index = 3;
        }
        dir = directions[index];
    }
    else
    {
        if (dir == directions[0])
        {
            y = y < 10 ? ++y : y;
        }
        else if (dir == directions[1])
        {
            x = x < 10 ? ++x : x;
        }
        else if (dir == directions[2])
        {
            y = y > 0 ? ++y : y;
        }
        else
        {
            x = x > 0 ? ++x : x;
        }
    }
    return st->getNewState(x, y, dir);
}

#include <variant>
#include <map>
#include <cmath>

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

struct Data
{
    int x, y;
    Direction direction;
};

class State
{
public:
    virtual Data getData() = 0;
    virtual void updateData(Data data) = 0;
    virtual State *getNewState(Data data) = 0;
    virtual ~State();
};

using NodeData = std::variant<int, Direction>;

struct Node
{
    NodeData data;
    Node *next;

    Node(NodeData data, Node *next) : data{data}, next{next} {}
    ~Node() { delete next; }
};

class LLState : public State
{
    Node *theList;

public:
    LLState(Data data)
    {
        theList = new Node{data.x, new Node{data.y, new Node{data.direction, nullptr}}};
    }
    Data getData()
    {
        int x = std::get<int>(theList->data);
        int y = std::get<int>(theList->next->data);
        Direction dir = std::get<Direction>(theList->next->next->data);
        return {x, y, dir};
    }

    void updateData(Data data)
    {
        theList->data = data.x;
        theList->next->data = data.y;
        theList->next->next->data = data.direction;
    }

    State *getNewState(Data data)
    {
        return new LLState{data};
    }
    ~LLState()
    {
        delete theList;
    }
};

class Robot
{
    State *state;
    const int NUM_DIRECTIONS;
    std::map<CMD, int> turn;
    std::map<Direction, int> curDirections;
    Direction directions[];

public:
    Robot(State *state) : state{state}, NUM_DIRECTIONS{4}
    {
        turn[CMD::Forward] = 0;
        turn[CMD::TurnLeft] = -1;
        turn[CMD::TurnRight] = 1;

        curDirections[Direction::NORTH] = 0;
        curDirections[Direction::EAST] = 1;
        curDirections[Direction::SOUTH] = 2;
        curDirections[Direction::WEST] = 3;

        directions[0] = Direction::NORTH,
        directions[1] = Direction::EAST;
        directions[2] = Direction::SOUTH;
        directions[3] = Direction::WEST;
    }
    State *robotCtrl(CMD cmd)
    {
        Data data = state->getData();
        Direction curDirection = data.direction;
        int turning = turn[cmd];
        int curDirectionIndex = curDirections[data.direction];
        int i = (turning + curDirectionIndex) % NUM_DIRECTIONS;
        Direction updatedDirection = directions[i];
        data.direction = updatedDirection;

        if (!turning)
        {
            if (updatedDirection == Direction::NORTH)
            {
                data.y = std::min(data.y + 1, 10);
            }
            else if (updatedDirection == Direction::EAST)
            {
                data.x = std::min(data.x + 1, 10);
            }
            else if (updatedDirection == Direction::SOUTH)
            {
                data.y = std::max(data.y - 1, 0);
            }
            else
            {
                data.x = std::max(data.x - 1, 0);
            }
        }

        state->updateData(data);
        return state->getNewState(data);
    }
};

int main()
{
}

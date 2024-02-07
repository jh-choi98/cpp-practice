#include <variant>
#include <map>

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

public:
    Robot(State *state) : state{state} {}
    State *robotCtrl(State *state, CMD cmd)
    {
        Data data = state->getData();
        Direction curDirection = data.direction;
        int x = data.x;
        int y = data.y;

        const int NUM_DIRECTIONS = 4;
        std::map<CMD, int> turn;
        turn[CMD::Forward] = 0;
        turn[CMD::TurnLeft] = -1;
        turn[CMD::TurnRight] = 1;

        std::map<Direction, int> curDirections;
        curDirections[Direction::NORTH] = 0;
        curDirections[Direction::EAST] = 1;
        curDirections[Direction::SOUTH] = 2;
        curDirections[Direction::WEST] = 3;

        Direction directions[] = {
            Direction::NORTH,
            Direction::EAST,
            Direction::SOUTH,
            Direction::WEST,
        };

        int turningTo = turn[cmd];
        int curDirectionIndex = curDirections[data.direction];
        int i = (turningTo + curDirectionIndex) % NUM_DIRECTIONS;
        Direction updatedDirection = directions[i];

        // if (!turningTo)
        // {
        //     Data curData = state->getData();
        //     data.x += curData.x;
        //     data.y += curData.y;
        // }

        if (!turningTo)
        {
            if (curDirection == directions[0])
            {
                data.y = y < 10 ? ++y : y;
            }
            else if (curDirection == directions[1])
            {
                data.x = x < 10 ? ++x : x;
            }
            else if (curDirection == directions[2])
            {
                data.y = y > 0 ? ++y : y;
            }
            else
            {
                data.x = x > 0 ? ++x : x;
            }
        }

        data.direction = updatedDirection;

        return state->getNewState(data);
    }
};

int main()
{
}

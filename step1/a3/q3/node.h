#ifndef __NODE_H__
#define __NODE_H__

#include "state.h"
#include "stateValue.h"
#include "enum.h"
#include <variant>
#include <memory>

using NodeData = std::variant<int, Direction>;

class Node : public State
{

protected:
    NodeData data;
    std::unique_ptr<Node> next;

public:
    Node();
    Node(NodeData data);
    Node(int x, int y, Direction dir);
    StateValue getStateValue() override;
    unique_ptr<State> getNewState(int x, int y, Direction dir) override;

    ~Node();
};
#endif

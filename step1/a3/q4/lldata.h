#ifndef __LLDATA_H__
#define __LLDATA_H__

#include "data.h"

struct Node;

class LLData : public Data
{
    Node *node;

public:
    LLData(int x, int y, int z, int r);
    LLData(int x, int y, int z);
    DataValue getDataValue() override;
    ~LLData();
};

#endif

#ifndef __DATA_H__
#define __DATA_H__

struct DataValue
{
    int x, y, z, r = 0;
};

class Data
{
public:
    virtual DataValue getDataValue() = 0;
    virtual ~Data(){};
};

#endif

// For redability, make point and sphere abstract

#ifndef __RGB_H__
#define __RGB_H__

struct RGB
{
    int r, g, b;

    bool operator==(const RGB &other) const;
    bool operator<(const RGB &other) const;

    static RGB RED()
    {
        return {255, 0, 0};
    }
    static RGB GREEN()
    {
        return {0, 255, 0};
    }
    static RGB BLUE()
    {
        return {0, 0, 255};
    }

    static RGB BLACK()
    {
        return {0, 0, 0};
    }

    static RGB WHITE()
    {
        return {255, 255, 255};
    }

    static RGB YELLOW()
    {
        return {255, 255, 0};
    }

    static RGB MAGENTA()
    {
        return {255, 0, 255};
    }

    static RGB CYAN()
    {
        return {0, 255, 255};
    }

    static RGB UNKNOWN()
    {
        return {-1, -1, -1};
    }
};

// to use unpacking, improving convienence for clinets

#endif

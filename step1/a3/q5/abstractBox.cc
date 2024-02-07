#include "abstractBox.h"
#include <cmath>
#include <algorithm>

using namespace std;

AbstractBox::AbstractBox(int xmin, int xmax, int ymin, int ymax)
    : xmin{xmin}, xmax{xmax}, ymin{ymin}, ymax{ymax} {}
AbstractBox::~AbstractBox() {}
MinMax AbstractBox::getXMinMax() { return {xmin, xmax}; }
MinMax AbstractBox::getYMinMax() { return {ymin, ymax}; }
float AbstractBox::getBoxCenterX()
{
    float fxmin = xmin;
    float fxmax = xmax;

    return (fxmin + fxmax) / 2;
};
float AbstractBox::getBoxCenterY()
{
    float fymin = ymin;
    float fymax = ymax;

    return (fymin + fymax) / 2;
};
float getWidth(AbstractBox *r)
{
    MinMax x = r->getXMinMax();
    float fxmin = x.min;
    float fxmax = x.max;

    return fxmax - fxmin;
}

float getHeight(AbstractBox *r)
{
    MinMax y = r->getYMinMax();
    float fymin = y.min;
    float fymax = y.max;

    return fymax - fymin;
}

bool AbstractBox::doesOverlap(AbstractBox *o)
{
    float x1DistanceFromCenter = getWidth(this) / 2;
    float y1DistanceFromCenter = getHeight(this) / 2;

    float x2DistanceFromCenter = getWidth(o) / 2;
    float y2DistanceFromCenter = getHeight(o) / 2;

    bool doesOverlapX = abs(getBoxCenterX() - o->getBoxCenterX()) < x1DistanceFromCenter + x2DistanceFromCenter;
    bool doesOverlapY = abs(getBoxCenterY() - o->getBoxCenterY()) < y1DistanceFromCenter + y2DistanceFromCenter;

    return doesOverlapX && doesOverlapY;
}
int AbstractBox::getOverlapArea(AbstractBox *o)
{
    if (doesOverlap(o))
    {
        int overlapXMin = max(getXMinMax().min, o->getXMinMax().min);
        int overlapXMax = min(getXMinMax().max, o->getXMinMax().max);

        int overlapYMin = max(getYMinMax().min, o->getYMinMax().min);
        int overlapYMax = min(getYMinMax().max, o->getYMinMax().max);

        return (overlapXMax - overlapXMin) * (overlapYMax - overlapYMin);
    }
    return 0;
}

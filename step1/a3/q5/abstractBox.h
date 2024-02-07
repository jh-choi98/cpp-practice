struct MinMax
{
    int min, max;
};

class AbstractBox
{
    int xmin, xmax, ymin, ymax;

public:
    AbstractBox(int xmin, int xmax, int ymin, int ymax);
    float getBoxCenterX();
    float getBoxCenterY();
    MinMax getXMinMax();
    MinMax getYMinMax();
    bool doesOverlap(AbstractBox *o);
    int getOverlapArea(AbstractBox *o);
    virtual ~AbstractBox() = 0;
};

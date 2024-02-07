class AbstractBox
{
public:
    virtual int getOverlapArea(AbstractBox *o) = 0;
    virtual ~AbstractBox();
};

class BaseBox : public AbstractBox
{
public:
    float getBoxCenterX();
    float getBoxCenterY();
    MinMax getXMinMax();
    MinMax getYMinMax();
    bool doesOverlap(AbstractBox *o);
};

struct Node
{
    int data;
    Node *next;

    Node(int data) : data{data}, next{nullptr} {}
    Node(int data, Node *next) : data{data}, next{next} {}
    ~Node() { delete next; }
};

#include <variant>
#include <string>
#include <unordered_map>
#include "abstractCardList.h"
#include "enum.h"
using InputData = std::variant<int, std::string>;

class AbstractCardProcessor {
    std::unordered_map<InputData, Card>inputToCardMap;
public:
    AbstractCardProcessor();
    bool isCard(InputData input);
    bool isEqual(Card c1, Card c2);
    virtual AbstractCardList* sortCards(AbstractCardList* cl) = 0;
    virtual AbstractCardList* removeOneOfEach(AbstractCardList* cl) = 0;
    virtual AbstractCardList* findKind(int n, AbstractCardList* cl) = 0;
};
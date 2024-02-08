#include "abstractCardProcessor.h"
#include "lLCardList.h"

class LLCardProcessor : public AbstractCardProcessor {
public:
    LLCardProcessor();
    AbstractCardList* sortCards(AbstractCardList* cl) override;
    AbstractCardList* removeOneOfEach(AbstractCardList* cl) override;
    AbstractCardList* findKind(int n, AbstractCardList* cl) override;
};
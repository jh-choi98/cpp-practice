#include "abstractCardProcessor.h"

AbstractCardProcessor::AbstractCardProcessor() {
    inputToCardMap[3] = Card::Three;
    inputToCardMap[4] = Card::Four;
    inputToCardMap[5] = Card::Five;
    inputToCardMap[6] = Card::Six;
    inputToCardMap[7] = Card::Seven;
    inputToCardMap[8] = Card::Eight;
    inputToCardMap[9] = Card::Nine;
    inputToCardMap[10] = Card::Ten;
    inputToCardMap["Jack"] = Card::Jack;
    inputToCardMap["Queen"] = Card::Queen;
    inputToCardMap["King"] = Card::King;
    inputToCardMap["Ace"] = Card::Ace;
    inputToCardMap[2] = Card::Two;
    inputToCardMap["Black"] = Card::Black;
    inputToCardMap["Red"] = Card::Red;
}

bool AbstractCardProcessor::isCard(InputData input) {
    return inputToCardMap.count(input);
}

bool AbstractCardProcessor::isEqual(Card c1, Card c2) {
    return c1 == c2;
}
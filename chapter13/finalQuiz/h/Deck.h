#pragma once
#include <array>
#include "Card.h"
class Deck 
{
private:
    static constexpr int deckSize = 52;
    std::array<Card, deckSize> m_deck;
    int m_cardIndex{0};
public:
    Deck();
    ~Deck(){};

    void print()const;
    void shuffle();
    const Card& dealCard();

};



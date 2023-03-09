#pragma once
#include "Deck.h"
class Player
{
private:
    const int BUST_Score {21};
protected:
    int m_score{0};
public:
    Player(){};
    ~Player(){};
    int drawCard(Deck& deck);
    bool isBust();
    int score();
};


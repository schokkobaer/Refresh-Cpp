#include "Player.h"
#include "Card.h"
int Player::drawCard(Deck &deck)
{
    int mTmpCardValue = deck.dealCard().value();
    m_score += mTmpCardValue;
    return mTmpCardValue;
}

bool Player::isBust()
{
    return m_score >= BUST_Score;
}

int Player::score()
{
    return m_score;
}

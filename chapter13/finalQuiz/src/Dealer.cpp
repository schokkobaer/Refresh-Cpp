#include "Dealer.h"

bool Dealer::shouldContinueDrawing()
{
    return m_score > MIN_VALUE_SCORE;
}
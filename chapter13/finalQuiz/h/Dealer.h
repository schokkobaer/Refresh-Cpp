
# pragma once
# include "Player.h"
class Dealer: public Player
{
    public:
        Dealer(){};
        ~Dealer(){};
        bool shouldContinueDrawing();
    private:
        const int MIN_VALUE_SCORE {17};
        
}; 
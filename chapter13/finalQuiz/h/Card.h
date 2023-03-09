#pragma once
class Card
{
    //Enums which should be associated with the class
    public:
        enum CardSuit
        {
            club,
            diamond,
            heart,
            spade,

            max_suits
        };

        enum CardRank
        {
            rank_2,
            rank_3,
            rank_4,
            rank_5,
            rank_6,
            rank_7,
            rank_8,
            rank_9,
            rank_10,
            rank_jack,
            rank_queen,
            rank_king,
            rank_ace,

            max_ranks
        };
    //---------------------------------------
    //---------------------------------------
    //--- Implementation of the class -------

    private:
        CardRank  m_rank;
        CardSuit m_suit;
    public:

        Card(CardRank rank = CardRank::rank_2, CardSuit suit = CardSuit::club);

        void print() const;

        int value() const;
};
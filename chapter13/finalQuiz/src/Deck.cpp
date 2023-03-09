#include "Deck.h"
#include <iostream>
#include <random> // std::mt19937
#include <algorithm> // std::shuffle
#include <ctime> // std::time
Deck::Deck()
{
    int index = 0;
    for (int suit{ 0 }; suit < static_cast<int>(Card::CardSuit::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(Card::CardRank::max_ranks); ++rank)
        {
            m_deck[index]= Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
            ++index;
        }
    }
}

void Deck::print() const
{
    for (const auto& card : m_deck)
    {
        card.print();
        std::cout << ' ';
    }

    std::cout << '\n';
}

void Deck::shuffle()
{
    m_cardIndex = 0; // Resets the deck when shuffling
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(m_deck.begin(), m_deck.end(), mt);
}

const Card &Deck::dealCard()
{
    if (m_cardIndex > (deckSize-1) )
    {
        std::cout << "No cards are left. Returning the last card\n";
        return m_deck[deckSize-1];
    }
    return m_deck[m_cardIndex++];
}

#pragma once
#include <iostream>
#include <sstream>
#include <array>
#include <random>
#include <algorithm>
enum Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    MAX_RANK
};
enum Suit
{   
    CLUB,
    DIAMOND,
    HEART,
    SPADE,
    MAX_SUIT
};

struct Card
{
    Rank m_rank;
    Suit m_suit;
};
std::string cardToString(const Card& card)
{
    std::stringstream ss;

    switch (card.m_rank)
    {
        case TWO:       ss << 2; break;
        case THREE:     ss << 3; break;
        case FOUR:      ss << 4; break;      
        case FIVE:      ss << 5; break;      
        case SIX:       ss << 6; break;      
        case SEVEN:     ss << 7; break;      
        case EIGHT:     ss << 8; break;      
        case NINE:      ss << 9; break;      
        case TEN:       ss << 10; break;      
        case JACK:      ss << "J"; break;      
        case QUEEN:     ss << "Q"; break;      
        case KING:      ss << "K"; break;      
        case ACE:       ss << "A"; break;      
        default:        ss << "???"; break;
        break;
    };

    switch (card.m_suit)
    {
        case Suit::SPADE:           ss << "S";break;
        case Suit::DIAMOND:         ss << "D";break;
        case Suit::CLUB :           ss << "C";break;
        case Suit::HEART :          ss << "H";break;
        default:                    ss << "!!!";break;
        break;
    }
    return ss.str();
}

void printCard(const Card& card)
{
    std::cout << cardToString(card)<< std::endl;

}

using Deck = std::array<Card, 52> ;

Deck createDeck()
{
    //Create deck
    Deck deck;
    //Initialize the deck
    int counter  = 0;
    for (int rank = 0; rank<Rank::MAX_RANK; rank++)
    {
        for (int suit = 0; suit <Suit::MAX_SUIT; suit++)
        {
            deck.at(counter) = Card{static_cast<Rank>(rank), static_cast<Suit>(suit)};
            counter++;
        }      
    }
    return deck;
}

void printDeck(const Deck& deck)
{
    for (const auto& card: deck)
    {
        std::cout << cardToString(card)<< " ";
    }
    std::cout << "\n";
}

void shuffleDeck(Deck& deck)
{
    static std::random_device rd;
    static std::mt19937 g(rd());
 
    std::shuffle(deck.begin(), deck.end(), g);

}

int getCardValue(const Card& card)
{
    int offset = 2; // As the lowest card is two but the casting the enum to int will produce 0 for two e.g Jack would be 9
    if (card.m_rank < Rank::JACK)
    {
        return static_cast<int>(card.m_rank) + offset;
    }
    if (card.m_rank == Rank::ACE)
    {
        return 11;
    }
    else 
        return 10;
}
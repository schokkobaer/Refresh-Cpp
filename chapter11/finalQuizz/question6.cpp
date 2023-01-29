#include "Cards.h"
int main(int argc, char const *argv[])
{
    Card testCard {Rank::SEVEN, Suit::DIAMOND};
    printCard(testCard);
    std::cout << "\n";
    Deck deck = createDeck();
    printDeck(deck);
    for (const auto& card: deck)
    {
        std::cout << getCardValue(card) << " ";
    }
    std::cout << std::endl;
    std::cout << "Shuffle the deck----------------------\n";
    shuffleDeck(deck);
    printDeck(deck);
    std::random_device rd;
    std::mt19937 g(rd());
    int randomNumber = g();
    std::cout << "Random number: "<<randomNumber<<std::endl;
    for (const auto& card: deck)
    {
        std::cout << getCardValue(card)<< " ";
    }
    std::cout << std::endl;

    return 0;
}


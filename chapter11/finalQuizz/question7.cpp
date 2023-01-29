#include "Cards.h"
#include <limits>
constexpr int g_bustValue = 21;
constexpr int g_maxDealerScore = 17;
enum class HitOrStand
{
    Hit,
    Stand
};
HitOrStand askUserIfHeWantsToHitOrStand()
{
    char userInput{'0'};
    do{
        std::cout << "Do you want to hit/continue( Press h) or stand (Press s): ";
        std::cin>> userInput;
        // Clear the remaining elements in the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(userInput !='s' && userInput!='h' )
        {
            std::cout<< "Please enter a valid character and press enter. Press \"h\" to hit or \"s\" to stand.\n";
            
        }
    }
    while(userInput !='s' && userInput!='h' );

    if (userInput == 's') return HitOrStand::Stand;
    else return HitOrStand::Hit;

}

int drawACardAndGetValue(const Deck& deck, int& index)
{
    std::cout << "The following card has been drawn: "<< cardToString(deck.at(index))<<std::endl;
    int returnValue = getCardValue(deck.at(index));
    index++; 
    return returnValue;

}
int getFavorableScoreForPlayer(int cardValue, int playerScore)
{
    // If the player gets an ace which would normaly have value of 11 in is dealt in his favor and converted to value of 1 if he would go bust
    if (cardValue == 11)
        return (playerScore+cardValue >= g_bustValue)? 1 : 11;
    else 
        return cardValue;
}

int drawCardForPlayerAndGetValue(const Deck& deck, int& index, int playerScore)
{
   return getFavorableScoreForPlayer (drawACardAndGetValue(deck,index), playerScore);
}
/**
 * This function should allow the user to play the the game Blackjack
 * @param Deck aka std::array<Card, 52> This should represent a shuffled deck
 */
void playBlackJack(Deck& deck)
{
    // To know where we are in the deck we can use index 
    int cardIndex{0};
    // There exist two score thos of the player and those of the dealer
    int dealerScore{0};
    int playerScore{0};
    bool looseFlag{false};
    dealerScore += drawACardAndGetValue(deck, cardIndex);
    std::cout << "The dealer has a total score of "<< dealerScore <<std::endl;

    playerScore += drawCardForPlayerAndGetValue(deck, cardIndex, playerScore);
    std::cout << "You have a total score of "<< playerScore << std::endl;
    playerScore += drawCardForPlayerAndGetValue(deck, cardIndex, playerScore);
    std::cout << "You have a total score of "<< playerScore << std::endl;
    while ( askUserIfHeWantsToHitOrStand() == HitOrStand::Hit)
    {
        playerScore += drawCardForPlayerAndGetValue(deck, cardIndex, playerScore);
        std::cout << "You have a total score of "<< playerScore << std::endl; 
        if (playerScore >= g_bustValue){
            std::cout << "Bust!!!!  Your score is above or equal "<< g_bustValue<< ". You loose :(.\n"<<std::endl;
            looseFlag = true;
            break;
        }
    }

    // The dealer now has to draw cards until he reaches a score above 17
    if (looseFlag == false)
    {
        while (dealerScore < g_maxDealerScore)
        {
            dealerScore += drawACardAndGetValue(deck, cardIndex);
            std::cout << "The dealer has a total score of "<< dealerScore <<std::endl; 
        }
        if (dealerScore >= g_bustValue)
        {
            std::cout << "The dealer went overboard. \n";
        }
        if (dealerScore > playerScore)
        {
            looseFlag = true;
        } 
        if (looseFlag)
        {
            std::cout << "The dealer archieved a higer score than you. You loose.\n";
        }
        else if (playerScore == dealerScore){
            std::cout<< "The dealer and you have the same score. It is a tie.\n";}
            else{
            std::cout << "Congratulation!!!! You win :)\n";}     
    } 
}

int main(int argc, char const *argv[])
{
    Deck playerDeck = createDeck();
    shuffleDeck(playerDeck);
    playBlackJack(playerDeck);
    return 0;
}

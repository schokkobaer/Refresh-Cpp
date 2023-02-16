#include <iostream>
#include <tuple>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include <cmath>
std::tuple<int, int> askUserForStartAndNumbers()
{
    int startNumber;
    int numberOfNumbers;

    std::cout << "Start where? ";
    std::cin >> startNumber;
    std::cout << "How many? ";
    std::cin >> numberOfNumbers;
    return {startNumber, numberOfNumbers};
}

std::vector<int> generateSquareNumber(int startNumber, int numberOfSquare)
{
    std::vector<int> squareList{};
    for (int i = 0; i<numberOfSquare;i++ )
    {
        squareList.push_back(startNumber * startNumber);
        startNumber++;
    }
    return squareList;
}
int getRandomValue234()
{
    static std::mt19937 mt{ std::random_device{}() }; // this gets created and seeded every time the function is called
    static std::uniform_int_distribution multiplicator{ 2,4 };
    return multiplicator(mt);
}

std::tuple<bool, int, int> checkUserInput(int userInput,const std::vector<int>& squareList)
{
    // Check if the number exist in the list
    int difference{std::numeric_limits<int>::max()}; 
    int closestValue = 0;
    auto foundValueIterator = std::find_if(squareList.begin(), squareList.end(), [userInput, &difference, &closestValue](const int value){
        if (std::abs (value - userInput) <difference)
        {
            difference =  std::abs (value - userInput);
            closestValue = value;
        }
        return value== userInput;
    });
    //Should return true if the value was found 
    return {foundValueIterator!= squareList.end(), difference, closestValue};
}
void startSquareGame()
{
    constexpr int MaxDiffToShowError = 4;
    //Ask user where he want to start
    //Ask user how many squares he wants to guess
    std::cout << "Starting the game\n";
    auto[startNumber, numberOfSquares] = askUserForStartAndNumbers();
    //Generate a list of square Numbers
    std::vector <int> squareList = generateSquareNumber(startNumber, numberOfSquares);

    //Generate a random Number between 2, 3 or 4 
    int multiplicator = getRandomValue234();
    //Multiply each square by the multiplicator
    std::for_each(squareList.begin(), squareList.end(), [multiplicator](int& x){
        x *= multiplicator;
    });
    for(const int value: squareList)
    {
        std::cout <<'\t'<< value << '\n';
    }
    std::cout <<"I generate "<< numberOfSquares << " square numbers. Do you know what each number is after multiplying it by 2?\n";
    // Let the user guess the correct numbers
    bool continueGame {true};
    while (continueGame)
    {
        int userGuess{0};
        std::cin >> userGuess;
        auto [valueFound, difference, closestValue] = checkUserInput(userGuess,squareList);
        if (!valueFound)
            {
                std::cout << userGuess << " is wrong.\n";
                if (difference <= MaxDiffToShowError )
                    std::cout << "You were off by "<< difference << ". The closes value was " << closestValue<<".\n";
                continueGame = false;
                break;
            }

        std::cout <<"Nice. You found a correct number\n";
        //Remove the value that was found from the list 
        squareList.erase(std::find(squareList.begin(), squareList.end(), closestValue) );
        if (squareList.size() <1)
        {
            std::cout << "Congratulation! You found all the correct numbers.\n";
            continueGame = false;
            break;
            
        }
        std::cout << squareList.size()<<" value reamain.\n";

    }

}
int main(int argc, char const *argv[])
{
    startSquareGame();
    
    return 0;
}

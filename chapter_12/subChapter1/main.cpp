#include <iostream>
#include <limits> // for std::numeric_limits
#include <functional>
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
bool checkIfExractionSucceded()
{
    if (std::cin.fail()) 
    {
        // yep, so let's handle the failure
        std::cin.clear(); // put us back in 'normal' operation mode
        ignoreLine(); // and remove the bad input
        return false;
    }
    else
        return true;
}
bool checkIfOperatorIsValid(const char operatorCharacter)
{
    switch (operatorCharacter)
    {
    case '*': return true;
    case '+': return true;
    case '-': return true;
    case '/': return true;
    default: return false;
    }
}
void askUser()
{
    std::cout << "Please enter a number followed by the operator and a second number: ";
}
struct SimpleCalculation
{
    double firstNumber{0};
    double secondNumber{0};
    char operatorCharacter{'0'};
};
SimpleCalculation aksUserForCalculation()
{
    bool questionisAnswared {false};
    double num1{0};
    char ope{'0'};
    double num2{0};
    while (!questionisAnswared)
    {
        askUser();
        std::cin>> num1;
        if(! checkIfExractionSucceded()) 
        {
                std::cout << "Please enter a number first\n";
                continue;
        }
        std::cin >> ope;
        if(! checkIfExractionSucceded() || !checkIfOperatorIsValid(ope)) 
        {
            std::cout << "Please enter a valid character: \"+\", \"-\", \"*\" \"/\"\n";
            continue;
        }
        std::cin >> num2;
        if(! checkIfExractionSucceded()) 
        {
                std::cout << "Please enter a second number after the operator\n";
                continue;
        }
        questionisAnswared = true;
    }
    return {num1, num2, ope};

}

int add(int num1, int num2)
{
    return num1 + num2;
}

int substract (int num1, int num2)
{
    return num1 - num2;
}
int multiply(int num1, int num2)
{
    return num1 * num2;
}
int divide(int num1, int num2)
{
    //Please note that this will result in trunctation the values behind the comma
    return num1/num2;
}

using ArithmeticFunction = std::function<int(int, int)>;
ArithmeticFunction getArithmeticFunction(const char operatorCharacter)
{
    switch ( operatorCharacter)
    {
    case '+': return add;
    case '-': return substract;
    case '*': return multiply;
    case '/': return divide;
    default:
    {
        std::cout << "Please enter a valid character: \"+\", \"-\", \"*\" \"/\" ." ;
        return nullptr;
    }

    }
} 
int main(int argc, char const *argv[])
{
    SimpleCalculation userCalculation = aksUserForCalculation();
    std::cout << "Your calculation with the result: ";
    std::cout << userCalculation.firstNumber << " "
    << userCalculation.operatorCharacter<< " "
    << userCalculation.secondNumber<< " = ";
    ArithmeticFunction desiredFunction = getArithmeticFunction(userCalculation.operatorCharacter);
    if (desiredFunction) // Check if the function is not a nullptr
        std::cout << desiredFunction(static_cast<int>(userCalculation.firstNumber), static_cast<int>(userCalculation.secondNumber))<<std::endl;
    return 0;
}

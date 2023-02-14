#include <iostream>
#define Question1 0
#define Question2 0
#define Question3 1
int factorial(int number)
{
    if (number== 0)
        return 1;
    else 
        return number*factorial(number-1);
}
int askUserForNumber()
{
    std::cout << "Please enter a number for which you would like to know the factorial: ";
    int num;
    std::cin >> num;
    return num;

}
int sumOfDigits(int inputNumber)
{
    int static sum{0};
    if (inputNumber< 0 )
    {
        //Just make sure that the number is positive
        inputNumber = -inputNumber;
    }
    if (inputNumber< 10)
        return sum += inputNumber;
    else 
        sum += (inputNumber % 10);
        sumOfDigits(static_cast<int>(inputNumber/10));
        return sum;
}

void invertBinaryNumber (std::string& invertBinaryNumber)
{
    for (int i = 0; i<invertBinaryNumber.size(); i++)
        if (invertBinaryNumber[i] == '0')
            invertBinaryNumber[i] = '1';
        else 
            invertBinaryNumber[i] = '0';
    
}

void addOne(std::string& invertBinaryNumber)
{
    //This function adds 1 to the binary number given as a string, assuming the the least signficant bit is a the left.
    for (int i = 0; i<invertBinaryNumber.size(); i++)
    {
        if (invertBinaryNumber[i] == '1')
            invertBinaryNumber[i] = '0';
        else
            invertBinaryNumber[i] = '1';
            break;
    }
}

std::string getReverseBinaryFromInteger(const unsigned int decimalNumber)
{
    if (decimalNumber<=1)
        return std::to_string(decimalNumber);
    else 
        return   getReverseBinaryFromInteger(decimalNumber/2)+ std::to_string(decimalNumber%2);
        

}
int main(int argc, char const *argv[])
{
    #if Question1
    std::cout << "-----------------\n";
    std::cout << "Question 1: \n";
    int  userNumber = askUserForNumber();
    int factorialNumber = factorial(userNumber);
    std::cout << userNumber<<"! = "<< factorialNumber<< '\n';
    constexpr int maxFactorialIWantToKnwo = 7;
    for (int i = 0; i<= maxFactorialIWantToKnwo; i++)
    {
        std::cout << factorial(i)<< " ";
    }
    std::cout << '\n';
    #endif

    #if Question2
    std::cout << "-------------------\n";
    std::cout << "Question 2\n";
    int testNumber = 93427 ;
    std::cout << "Calculating the some of each digit of the number "<< testNumber << ". The sum is "<< sumOfDigits(testNumber)<< ".\n";
    #endif

    #if Question3
    std::cout << "-------------------\n";
    std::cout << "Question 3a\n";
    std::cout << "Please enter an integer:";
    int userInput{0};
    std::cin >> userInput;
    std::string reverseBinary = getReverseBinaryFromInteger(static_cast<unsigned int>(userInput));
    std::cout << "The binary for the decimal number "<<userInput << " starting with the least significant bit is: "<< reverseBinary << ".\n";
    #endif
    return 0;
}

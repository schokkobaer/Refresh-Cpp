#include <iostream>

void printCStyleString(const char* inputWord)
{
    while(*inputWord!= '\0')
    {
        std::cout<< *inputWord;
        inputWord++;
    }
    std::cout << '\n';

}
int main(int argc, char const *argv[])
{
    const char* testWord= "Hello World";
    printCStyleString(testWord);
    return 0;
}     
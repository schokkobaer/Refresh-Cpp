#include <iostream>

int main(int argc, char const *argv[])
{
    if (argc <= 1)
    {
        if (argv[0]) // On some operating system the first argumen may be empty instead of holding the function name
        {
            // If the function name is given
            std::cout << "Usage of the function "<< argv[0] <<". You should add some words after calling this function\n";
        }
        else
        {
            //If the first parameter is empty
            std::cout << "Please enter some other variables.\n";
        }
        return 0;
    }
    std::cout << "You used the function "<< argv[0]<< '\n';
    std::cout << "You entered the follwing parameters: \n";
    for (int i {1}; i< argc; i++)
    {
        std::cout << "\t "<< argv[i]<< '\n';
    }

    return 0;
}

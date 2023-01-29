#include<iostream>
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace Animal
{
    enum Animal
    {
        chicken,
        dog,
        cat, 
        elephant,
        duck,
        snake,
        max_animal,
    };
}
std::string animalToString(Animal::Animal inputAnimal)
{
    switch (inputAnimal)
    {
    case Animal::cat:
        return "cat";
        break;
    case Animal::dog:
        return "dog";
        break;
    case Animal::chicken:
        return "chicken";
        break;
    case Animal::elephant:
        return "elephant";
        break;
    case Animal::duck:
        return "duck";
        break;
    case Animal::snake:
        return "snake";
        break;
    default:
        return "???";
        break;
    }
}

int main(int argc, char const *argv[])
{
    double temperatur[365]{};
    Animal::Animal animmals[]{Animal::chicken, Animal::dog, Animal::cat, Animal::elephant, Animal::duck, Animal::snake};

    int animalLegs[Animal::max_animal]{2, 4, 4, 4, 2, 0};
    for (int i = 0; i< Animal::max_animal; i++)
    {
        std::cout<<"A "<< animalToString(animmals[i]) << " has "<< animalLegs[animmals[i]] << " legs."<< std::endl;
    }

    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int sizeArray = sizeof(array)/ sizeof(array[0]);
    for (int i = 0; i< sizeArray ; i++)
    {
        std::cout <<array[i]<< std::endl;
    }

    int x = -1;
    while (x< 0 ||x >9)
    {

        std::cout << "Please enter a number between 1 and 9:  ";
        std::cin >> x;
        if (std::cin.fail())
            std::cin.clear(); // reset any error flags
        ignoreLine();
    }
    std::cout << "Thank you for entering the number "<< x<<"."<< std::endl;

    int index;
    for (int i = 0; i< sizeArray; i++)
    {
        if (array[i] == x)
        {
           index = i;
           std::cout << "Found the value "<< x << " at index "<< index <<". "<< std::endl;
           break;
        }

    
    }
    std::cout << "Given the above array, the value can be found at index "<< index << "."<<std::endl;
    return 0;
}

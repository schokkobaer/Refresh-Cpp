#include<iostream>
#include <iterator>

int* findValue(int* beginPtr, int* endPtr, int valueToFind)
{
    int distance = endPtr - beginPtr;
    if (distance <0)
    {
        std::cout << "The first pointer lays behing the seconde pointer\n";
        return endPtr;
    }
    
    for (int i{0}; i<distance; i++)
    {
        if (beginPtr[i] == valueToFind)
            return beginPtr+i;
    }
    return endPtr;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ findValue(std::begin(arr), std::end(arr), 17) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}

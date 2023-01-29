#include <iostream>

template <typename T>
void swapValues(T& a, T& b)
{
    T tempValue = a;
    a = b;
    b = tempValue;
}

int main(int argc, char const *argv[])
{
    int a = 50;
    int b = 80;
    std::cout << "a contains: "<< a<<std::endl;
    std::cout << "b contains: "<<b<<std::endl;

    std::cout << "Swapping Values"<< std::endl;
    
    swapValues(a, b);
    std::cout << "a contains: "<< a<<std::endl;
    std::cout << "b contains: "<<b<<std::endl;
    return 0;
}

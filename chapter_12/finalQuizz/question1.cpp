#include <iostream>
#include <array>
double randomFunction(double i, double j)
{
    return (i>j)? i : j;
}

void swapValue(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
int main(int argc, char const *argv[])
{
    //A function prototy of a maximum function
    double (*max)(const double x , const double y){randomFunction};
    std::cout << max(3, 5)<< '\n';
    
    // A function prototype to swar two values
    void (*swap)(int&, int&){swapValue};
    int a = 5;
    int b = 10;
    std::cout << "a: "<< a << " b:"<< b << '\n';
    swap(a, b);
    std::cout << "Swaping -------\n";
    std::cout << "a: "<< a << " b:"<< b << '\n';

    int& (*getLargestElement)(int array[], int length);
    return 0;


}

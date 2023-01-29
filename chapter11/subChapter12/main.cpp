#include <iostream>
#include <algorithm>
int main(int argc, char const *argv[])
{
    // Get number of names the user wants to save
    int numNames{};
    std::cout << "How many names would you like to enter?: ";
    std::cin >> numNames;
    std::string tempName = "";
    //std::string* nameList{new std::string[numNames]};
    std::string nameList[numNames];
    for (int i{0}; i< numNames; i++)
    {
        std::cout << "Please enter a name number #"<<i+1<<":  ";
        std::cin >> tempName;
        nameList[i] = tempName;
    }

    // Sort the names
    std::sort(nameList, nameList+numNames);
    std::cout << '\n';
    std::cout << "Here is your sorted list\n";
    // Print the names
    for (int i = 0; i<numNames; i++)
    {
        std::cout <<"Name number #"<< i+1 << ": "<< nameList[i]<<std::endl;
    }

    //delete []nameList;
    return 0;
}

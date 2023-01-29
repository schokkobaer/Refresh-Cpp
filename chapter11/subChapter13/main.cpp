#include<iostream>
std::string getNameFromUser()
{
    std::string nameFromUser;
    std::cout <<"Please Enter a name: ";
    std::cin >> nameFromUser;
    return nameFromUser;
}


int main(int argc, char const *argv[])
{
    std::string testNames[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Gred", "Holly"};
    std::string name {getNameFromUser()};
    bool found{false};
    for (const std::string& nameInList: testNames)
    {
        if(nameInList == name)
        {
            found = true;
            break;
        }
    }

  std::cout << "The name was "<< name <<(found? " ": " not ")<< "found in the list\n";
    return 0;
}

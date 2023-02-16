#include <iostream>
#include <array>
#include <algorithm>
struct Student
{
    std::string m_name;
    int m_points;
};

int main(int argc, char const *argv[])
{
    std::array<Student, 8> arr{
  { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
};

auto bestStudentPtr =  std::max_element(arr.begin(), arr.end(), 
                                [](const Student& smaller, const Student bigger)
                                {return  bigger.m_points>smaller.m_points;});
std::cout << "The best student is "<< bestStudentPtr->m_name<< ". He/She has "<< bestStudentPtr->m_points<< ".\n";
    return 0;
}


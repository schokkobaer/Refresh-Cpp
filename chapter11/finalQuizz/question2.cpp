#include <iostream>
# include <vector>
#include <algorithm>
struct Student
{
    std::string m_fistName;
    int m_grade;

};

Student askUserForStudentNameAndGrad()
{
    int grade;
    std::string name;
    std::cout << "Please enter the name of the student followed by their grade: ";
    std::cin >> name;
    std::cin >> grade;
    return {name, grade};
}
bool comparisonOfStudentGrades(const Student& student1, const Student& student2)
{
    return student1.m_grade> student2.m_grade;
}

int main(int argc, char const *argv[])
{
    //Asks user for number of students
    std::cout << "How many students to you want to regsiter: ";
    int numOfStudent;
    std::cin >> numOfStudent;

    std::vector<Student>studentList;
    for (int i = 0; i<numOfStudent; i++)
    {
        studentList.push_back(askUserForStudentNameAndGrad());
    }
    //Sort the list by grad
    std::sort(studentList.begin(), studentList.end(), comparisonOfStudentGrades);

    //Print the sorted list of students
    for (const auto& student: studentList)
    {
        std::cout << student.m_fistName << " got a grade of "<< student.m_grade<<"."<< std::endl; 
    }
    return 0;
}

#include "Stack.h"
#include <iostream>

bool Stack::push(int value)
{
    if (m_valueCounter < Max_Size)
    {
        m_data[m_valueCounter] = value;
        m_valueCounter +=1;
        return true; 
    }
}
void Stack::reset()
{
    m_valueCounter = 0;
}
void Stack::print()
{
    for (int i = 0; i< m_valueCounter; i++)
    {
        std::cout << m_data[i]<< " ";
    }
    std::cout << '\n';
}
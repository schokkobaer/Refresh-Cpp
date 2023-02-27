#include "Stack.h"
#include <iostream>
#include <cassert>

bool Stack::push(int value)
{
    if (m_valueCounter < Max_Size)
    {
        m_data[m_valueCounter] = value;
        m_valueCounter +=1;
        return true; 
    }
    return false;
}
void Stack::reset()
{
    m_valueCounter = 0;
}
int Stack::pop()
{
    assert(m_valueCounter>0);
    m_valueCounter -=1;
    return m_data[m_valueCounter];
}
void Stack::print()
{
    std::cout << "( ";
    for (int i = 0; i< m_valueCounter; i++)
    {
        std::cout << m_data[i]<< " ";
    }
    std::cout << ")\n";
}
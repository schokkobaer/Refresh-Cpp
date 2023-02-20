#include "IntPair.h"
#include <iostream>
void IntPair::print()
{
    std::cout << "Pair("<< m_p1 <<", "<< m_p2 <<")\n";
}

void IntPair::set(int p1, int p2)
{
    m_p1 = p1;
    m_p2 = p2;
}
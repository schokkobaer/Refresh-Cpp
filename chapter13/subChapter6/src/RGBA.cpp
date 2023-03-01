#include "RGBA.h"

RGBA::RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha):
m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha}
{
}

void RGBA::print()
{
    std::cout << "r="<< int(m_red)<<" g="<< int(m_green);
    std::cout<< " b= "<< int(m_blue)<< " a="<< int(m_alpha);
    std::cout << '\n'; 
}

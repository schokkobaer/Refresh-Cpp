#pragma once
#include <cstdint>
#include <iostream>
class RGBA
{
private:
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;

public:
    RGBA(std::uint8_t red = 0, std::uint8_t green = 0,std::uint8_t blue = 0, std::uint8_t alpha = 255);
    ~RGBA(){};

    void print();
};

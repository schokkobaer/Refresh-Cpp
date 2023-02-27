#pragma once
#include <string>
#include <iostream>
constexpr std::string_view BALL_DEFAULT_COLOR { "black"};
constexpr double BALL_DEFAUL_RADIUS = 10;
class Ball
{
private:
    std::string m_color{"black"};
    double m_radius{10};
public:
    /// @brief This is the constructor of the class
    /// @param color A color given as a string the default value is black
    /// @param radius The radius of the ball the default value is 10
    Ball(std::string_view color = BALL_DEFAULT_COLOR, double radius = BALL_DEFAUL_RADIUS);

    /// @brief This is another constructor of the class
    /// @param color A color given as a string the default value is black
    /// @param radius The radius of the ball the default value is 10
    Ball(double radius);

    /// @brief This function prints the color and the radius of the ball to the console.
    void print();
};


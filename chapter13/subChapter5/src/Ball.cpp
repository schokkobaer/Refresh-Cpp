#include "Ball.h"
Ball::Ball(std::string_view color, double radius):
m_color(color), 
m_radius(radius)
{
}


Ball::Ball(double radius){
    Ball(BALL_DEFAULT_COLOR, radius);
}

void Ball::print(){
    std::cout << "color: "<< m_color <<", radius: "<< m_radius<<"\n";
};

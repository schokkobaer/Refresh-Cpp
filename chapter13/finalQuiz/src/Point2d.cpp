#include "Point2d.h"
#include <iostream>
#include <cmath>
void Point2d::print()
{
    std::cout << "Point2d("<< m_x << ", "<< m_y <<")\n";
}

double Point2d::distanceTo(const Point2d &p2)
{
    return std::sqrt(std::pow((m_x - p2.m_x), 2)+ std::pow((m_y - p2.m_y), 2));
}

/** @brief This function calculates the distance between two points. Each point is defined
 *          by two parameters
 *
 *  @param p1 The first 2 dimensional point
 *  @param p2 The second 2 dimensional point
 *  @return The distance
 */
double distanceFrom(const Point2d &p1, const Point2d &p2)
{
     return std::sqrt(std::pow((p1.m_x - p2.m_x), 2)+ std::pow((p1.m_y - p2.m_y), 2));
}

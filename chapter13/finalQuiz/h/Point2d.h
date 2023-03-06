#pragma once 

/**
* A class respresinting a point in 2d, therefore by 2 variables namely m_x and m_y. 
 */
class Point2d
{
private:
    double m_x{0};/**<The first variable desribing a point in 2d */
    double m_y{0};/**<The second variable desribing a point in 2d */
public:
//Constructor
    Point2d(double x = 0, double y = 0): m_x{x}, m_y{y}{};

    //Deconsctor
    ~Point2d(){};

    void print();

    /** @brief This function calculates the distance between the point this class and any other point.
 *         Each point is defined by two parameters          
 *
 *  @param p1 The other 2 dimensional point
 *  @return The distance
 */
    double distanceTo(const Point2d& p2);
    
    /** @brief This function calculates the distance between two points. Each point is defined
 *          by two parameters
 *
 *  @param p1 The first 2 dimensional point
 *  @param p2 The second 2 dimensional point
 *  @return The distance
 */
    friend double distanceFrom(const Point2d& p1, const Point2d& p2);


};


#pragma once

class Point3d
{
private:
   int m_x;
   int m_y;
   int m_z;
public:
    Point3d(/* args */):
    m_x(0),
    m_y(0),
    m_z(0){};
    ~Point3d(){};

    void setValues(int x, int y, int z);
    void print();
    bool isEqual(Point3d& point) const;
};


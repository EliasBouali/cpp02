#include "Point.hpp"

static Fixed sign(Point const &p1, Point const &p2, Point const &p3)
{
    Fixed res = (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
              - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
    return res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    Fixed zero(0);

    if (d1 == zero || d2 == zero || d3 == zero)
        return false;

    bool allNegative = (d1 < zero) && (d2 < zero) && (d3 < zero);
    bool allPositive = (d1 > zero) && (d2 > zero) && (d3 > zero);

    return (allNegative || allPositive);
}

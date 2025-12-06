#include <iostream>
#include "Point.hpp"

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point p1(3.0f, 3.0f);   // à l'intérieur
    //Point p2(10.0f, 10.0f); // dehors
   // Point p3(0.0f, 5.0f);   // sur un côté (devrait être false)
    //Point p4(5.0f, 0.0f);   // sur un autre côté (false)

    std::cout << std::boolalpha;

    std::cout << "p1 inside ? " << bsp(a, b, c, p1) << std::endl;
    //std::cout << "p2 inside ? " << bsp(a, b, c, p2) << std::endl;
    //std::cout << "p3 on edge ? " << bsp(a, b, c, p3) << std::endl;
    //std::cout << "p4 on edge ? " << bsp(a, b, c, p4) << std::endl;

    return 0;
}

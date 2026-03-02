#include "Point.hpp"
#include <stdbool.h>

float cross(Point const a, Point const b, Point const point)
{
    float abx = b.getX().toFloat() - a.getX().toFloat();
    float aby = b.getY().toFloat() - a.getY().toFloat();
    float apx = point.getX().toFloat() - a.getX().toFloat();
    float apy = point.getY().toFloat() - a.getY().toFloat();

    return (abx * apy - aby *apx);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    const float EPS = 0.0001f; 
    float d1 = cross(a, b, point);
    float d2 = cross(b, c, point);
    float d3 = cross(c, a, point);

    bool has_neg = (d1 < -EPS) || (d2 < -EPS) ||(d3 < -EPS);
    bool has_pos = (d1 > EPS) || (d2 > EPS) ||(d3 > EPS);

    // Logical negation: if has_neg and has_pos both are positive,
    // then the && is true, and after the ! is false
    return (!(has_neg && has_pos));
}
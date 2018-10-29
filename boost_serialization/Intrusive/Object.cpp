#include "Object.h"

Object::Object ()
    : x(0), y(0)
{}

Object::Object (const int x, const int y)
    : x(x), y(y)
{}


std::ostream& operator<< (std::ostream& os, const Object& obj)
{
    os << "x=" << obj.x
       << " y=" << obj.y;
    return os;
}

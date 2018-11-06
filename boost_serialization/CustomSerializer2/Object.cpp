#include "Object.h"
#include "archive_impl.h"

/*******************************************************************************

    Object      (custom serialization)

*******************************************************************************/

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

void Object::save_object(archive::oarchive_impl* ar)
{
    ar->oa << x
           << y;
}

void Object::load_object(archive::iarchive_impl* ar)
{
    ar->ia >> x
           >> y;
}

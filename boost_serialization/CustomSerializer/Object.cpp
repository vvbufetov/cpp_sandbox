#include "Object.h"
#include "archive_impl.h"

#include <boost/serialization/access.hpp>

/*******************************************************************************

    ObjectImpl      (boost serialization)

*******************************************************************************/

struct ObjectImpl {
    int x;
    int y;

    ObjectImpl ()
        : x(0), y(0)
    {}

    ObjectImpl (const int x, const int y)
        : x(x), y(y)
    {}

    // hidden boost serialization
    template<class Archive>
      void serialize(Archive & ar, const unsigned int version);
};

template<class Archive>
void ObjectImpl::serialize(Archive & ar, const unsigned int version)
{
    ar & x
       & y;
}

std::ostream& operator<< (std::ostream& os, const ObjectImpl& obj)
{
    os << "x=" << obj.x
       << " y=" << obj.y;
    return os;
}

/*******************************************************************************

    Object      (custom serialization)

*******************************************************************************/

Object::Object ()
    : impl(new ObjectImpl(0,0))
{}

Object::Object (const int x, const int y)
    : impl(new ObjectImpl(x,y))
{}

Object::~Object ()
{
    delete impl;
}

std::ostream& operator<< (std::ostream& os, const Object& obj)
{
    os << *obj.impl;
    return os;
}

void Object::save_object(archive::oarchive_impl* ar)
{
    ar->oa << impl;
}

void Object::load_object(archive::iarchive_impl* ar)
{
    ar->ia >> impl;
}



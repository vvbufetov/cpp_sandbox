#include "Object.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

/*******************************************************************************

    ObjectImpl

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

    template<class Archive>
      void serialize(Archive & ar, const unsigned int version);
};

template<class Archive>
void ObjectImpl::serialize(Archive & ar, const unsigned int version)
{
    ar & x & y;
}

std::ostream& operator<< (std::ostream& os, const ObjectImpl& obj)
{
    os << "x=" << obj.x
       << " y=" << obj.y;
    return os;
}

/*******************************************************************************

    Object

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

template<class Archive>
void Object::serialize(Archive & ar, const unsigned int version)
{
    ar & impl;
}

template
void Object::serialize<boost::archive::text_oarchive>
  (boost::archive::text_oarchive & ar, const unsigned int version);

template
void Object::serialize<boost::archive::text_iarchive>
  (boost::archive::text_iarchive & ar, const unsigned int version);

std::ostream& operator<< (std::ostream& os, const Object& obj)
{
    os << *obj.impl;
    return os;
}

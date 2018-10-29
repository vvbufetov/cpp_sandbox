#ifndef OBJECT_H_
#define OBJECT_H_

#include <ostream>
#include <boost/serialization/access.hpp>

struct ObjectImpl;

class Object {

 private:
    ObjectImpl* impl;

    friend class boost::serialization::access;

    template<class Archive>
      void serialize(Archive & ar, const unsigned int version);

 public:
    Object ();
    Object (const int x, const int y);
    ~ Object ();

    friend std::ostream& operator<< (std::ostream&, const Object&);
};

std::ostream& operator<< (std::ostream&, const Object&);

#endif // OBJECT_H_

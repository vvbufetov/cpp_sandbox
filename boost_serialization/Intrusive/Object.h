#ifndef OBJECT_H_
#define OBJECT_H_

#include <ostream>
#include <boost/serialization/access.hpp>

class Object {
 private:
    int x;
    int y;

    friend class boost::serialization::access;

    template<class Archive>
      void serialize(Archive & ar, const unsigned int version)
    {
        ar & x
           & y;
    }

 public:
    Object ();
    Object (const int x, const int y);

    friend std::ostream& operator<< (std::ostream&, const Object&);
};

std::ostream& operator<< (std::ostream&, const Object&);

#endif // OBJECT_H_

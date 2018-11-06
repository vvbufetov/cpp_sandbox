#ifndef OBJECT_H_
#define OBJECT_H_

#include <ostream>
#include "archive.h"

struct ObjectImpl;

class Object {
 private:
    int x,y;

    friend class archive::archive;
    void save_object(archive::oarchive_impl*);
    void load_object(archive::iarchive_impl*);

 public:
    Object ();
    Object (const int x, const int y);

    friend std::ostream& operator<< (std::ostream&, const Object&);
};

std::ostream& operator<< (std::ostream&, const Object&);

#endif // OBJECT_H_

#ifndef ARCHIVE_H_
#define ARCHIVE_H_

#include <iostream>

namespace archive {

struct oarchive_impl;
struct iarchive_impl;

class archive {
 protected:
    template<class T>
    void save_object(oarchive_impl* impl, T & t)
    {
        t.save_object( impl );
    }

    template<class T>
    void load_object(iarchive_impl* impl, T & t)
    {
        t.load_object( impl );
    }
};


class oarchive : archive {
 private:
    oarchive_impl* impl;

 public:
    oarchive (std::ostream& os);
    ~oarchive ();

    template<class T>
    oarchive& operator<< (T & t)
    {
        archive::save_object(impl, t);
        return *this;
    }
};


class iarchive : archive {
 private:
    iarchive_impl* impl;

 public:
    iarchive (std::istream& is);
    ~iarchive ();

    template<class T>
      iarchive& operator>> (T & t)
    {
        archive::load_object(impl, t);
        return *this;
    }
};

};

#endif // ARCHIVE_H_

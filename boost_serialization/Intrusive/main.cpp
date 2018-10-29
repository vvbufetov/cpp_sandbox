#include <iostream>
#include <sstream>
#include "Object.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


int main () {
    Object a;
    Object b(2,3);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << a
       << b;

    std::cout << "serialized: " << oss.str() << std::endl;

    std::istringstream iss(oss.str());
    boost::archive::text_iarchive ia(iss);
    ia >> a
       >> b;
    std::cout << "deserialized:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

}

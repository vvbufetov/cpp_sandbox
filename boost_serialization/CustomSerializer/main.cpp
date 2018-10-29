#include <iostream>
#include <sstream>
#include "Object.h"
#include "archive.h"

int main () {
    Object a;
    Object b(2,3);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::ostringstream oss;
    archive::oarchive oa(oss);
    oa << a
       << b;

    std::cout << "serialized: " << oss.str() << std::endl;

    std::istringstream iss(oss.str());
    archive::iarchive ia(iss);
    ia >> a
       >> b;
    std::cout << "deserialized:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}

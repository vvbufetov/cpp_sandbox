#include <iostream>
#include <sstream>

#include "Groups.h"
#include "archive.h"

int main () {
    Groups g;
    std::vector<int> vi = {2, 4, 6};
    g.add("first", vi);
    std::vector<double> vd = {1., 2., 3.};
    g.add("second", vd);
    std::cout << g << std::endl;

    std::cout
        << " i \t"
        << "first\t"
        << "second\t"
        << "third\n";
    for (int i = 0; i<10; i++)
        std::cout << i << "\t"
                  << g.group("first", i) << "\t"
                  << g.group("second", i) << "\t"
                  << g.group("third", i) << "\n";

    std::ostringstream oss;
    archive::oarchive oa(oss);
    oa << g;

    std::cout << "serialized: " << oss.str() << std::endl;

    Groups g2;
    std::istringstream iss(oss.str());
    archive::iarchive ia(iss);
    ia >> g2;

    std::cout
        << " i \t"
        << "first\t"
        << "second\t"
        << "third\n";
    for (int i = 0; i<10; i++)
        std::cout << i << "\t"
                  << g2.group("first", i) << "\t"
                  << g2.group("second", i) << "\t"
                  << g2.group("third", i) << "\n";

}

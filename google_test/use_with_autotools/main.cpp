#include <iostream>
#include "factorial.h"
#include <string>

int main (int argc, char ** argv) {
    if (argc != 2) {
        std::cout << "Usage: fact <number>" << std::endl;
        return 0;
    }
    unsigned int x = std::stol(argv[1]);
    std::cout << Factorial(x) << std::endl;
    return 0;
}

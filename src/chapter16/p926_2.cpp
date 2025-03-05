#include "./p926_0.hpp"
#include <iostream>

// templateBuild.cc
// instantiation file must provide a (nonextern) definition for every
// type and function that other files declare as extern
template int compare(const int &, const int &);
template class Blob<string>; // instantiates all members of the class template

int main(int argc, char *argv[]) {
    std::cout << compare(1, 2) << std::endl;
    Blob<string> blob{"apple", "what", "name"};
    std::cout << blob.front() << std::endl;
    return 0; //
}
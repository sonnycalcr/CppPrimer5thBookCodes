#include <iostream>

template <typename Foo> Foo calc(const Foo &a, const Foo &b) {
    Foo tmp = a; // tmp has the same type as the parameters and return type
    // ...
    return tmp; // return type and parameters have the same type
}

int main(int argc, char *argv[]) {
    std::cout << calc(1, 2) << std::endl;

    return 0; //
}
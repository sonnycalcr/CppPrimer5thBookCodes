#include <iostream>
typedef double A;
template <typename A, typename B> void f(A a, B b) {
    A tmp = a; // tmp has same type as the template parameter A, not double
    // double B;  // error: redeclares template parameter B
    std::cout << a << ", " << tmp << std::endl;
}

int main(int argc, char *argv[]) {
    f(2.0, 3.0);
    return 0; //
}
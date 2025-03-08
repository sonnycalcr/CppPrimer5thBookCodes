#include <iostream>
#include <string>

template <typename T> void f(T &&);      // binds to nonconst rvalues
template <typename T> void f(const T &); // lvalues and const rvalues

template <typename T> void f(T &&val) {
    std::cout << "f(T &&val) called with: " << val << std::endl; //
}

template <typename T> void f(const T &val) {
    std::cout << "f(const T &val) called with: " << val << std::endl; //
}

int main() {
    int x = 10;
    const int y = 20;

    f(30); //  rvalue

    f(x); // lvalue

    f(y); // const lvalue

    std::string str = "Hello";
    f(std::move(str)); // use std::move to convert lvalue to rvalue

    f(std::string("World")); // pass a rvalue

    return 0;
}

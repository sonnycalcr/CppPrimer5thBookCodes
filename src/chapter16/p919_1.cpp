#include <iostream>
#include <vector>

// p918_2
// T::size_type *p;

template <typename T> typename T::value_type top(const T &c) {
    if (!c.empty())
        return c.back();
    else
        return typename T::value_type();
}

int main(int argc, char *argv[]) {
    std::vector<int> vec01{1, 2, 3};
    std::cout << top(vec01) << std::endl;

    std::vector<int> vec02;
    std::cout << top(vec02) << std::endl;
    // T::value_type()
    std::cout << int() << std::endl;

    return 0; //
}
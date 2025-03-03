#include <iostream>

// ok: inline specifier follows the template parameter list
template <typename T> inline T min(const T &, const T &);

template <typename T> inline T min(const T &a, const T &b) {
    return a > b ? 1 : -1; //
}

int main(int argc, char *argv[]) {
    std::cout << min(1, 2) << std::endl;
    return 0; //
}
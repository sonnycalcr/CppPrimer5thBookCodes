// argument types can differ but must be compatible
#include <iostream>
template <typename A, typename B> int flexibleCompare(const A &v1, const B &v2) {
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    // p933_2
    long lng;
    int res = flexibleCompare(lng, 1024); // ok: calls flexibleCompare(long, int)
    std::cout << res << std::endl;
    return 0; //
}
#include <functional>
#include <iostream>

using namespace std;

// compare has a default template argument, less<T>
// and a default function argument, F()
template <typename T, typename F = less<T>> int compare(const T &v1, const T &v2, F f = F()) {
    if (f(v1, v2))
        return -1;
    if (f(v2, v1))
        return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    // p920_1
    bool i = compare(0, 42); // uses less; i is -1
    // result depends on the isbns in item1 and item2
    // Sales_data item1(cin), item2(cin);
    // bool j = compare(item1, item2, compareIsbn);
    std::cout << i << std::endl;
    return 0; //
}

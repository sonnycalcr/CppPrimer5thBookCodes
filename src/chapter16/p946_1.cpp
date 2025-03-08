#include <iostream>

int fcn(int t) {
    t++; //
    return t;
}

template <typename T> void f3(T &&val) {
    T t = val;      // copy or binding a reference?
    t = fcn(t);     // does the assignment change only t or val and t?
    if (val == t) { /* ... */
        std::cout << val << " val equals to t" << std::endl;
    } // always true if T is a reference type
}

int main() {
    int x = 5;
    f3(x);
    f3(10);

    return 0;
}
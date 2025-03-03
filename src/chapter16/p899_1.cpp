#include <functional>
#include <iostream>

using namespace std;

// version of compare that will be correct even if used on pointers; see § 14.8.2 (p.575)
template <typename T> int compare(const T &v1, const T &v2) {
    if (less<T>()(v1, v2))
        return -1;
    if (less<T>()(v2, v1))
        return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    int v1 = 12;
    int v2 = 10;
    cout << compare(v1, v2) << endl;
    return 0; //
}
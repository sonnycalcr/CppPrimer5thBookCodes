#include <iostream>

using namespace std;

// T1 cannot be deduced: it doesn't appear in the function parameter list
template <typename T1, typename T2, typename T3> T1 sum(T2, T3);

int main(int argc, char *argv[]) {
    int i = 1;
    long lng = 12;
    // p936_2
    // T1 is explicitly specified; T2 and T3 are inferred from the argument types
    auto val3 = sum<long long>(i, lng); // long long sum(int, long)
    cout << val3 << endl;
    return 0; //
}

template <typename T1, typename T2, typename T3> T1 sum(T2 v1, T3 v2) {
    return v1 + v2; //
}
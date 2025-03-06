#include <iostream>

using namespace std;

// poor design: users must explicitly specify all three template parameters
template <typename T1, typename T2, typename T3> T3 alternative_sum(T2, T1);

int main(int argc, char *argv[]) {
    int i = 1;
    long lng = 2;
    // p937_1
    // error: can't infer initial template parameters
    // auto val3 = alternative_sum<long long>(i, lng);
    // ok: all three parameters are explicitly specified
    auto val2 = alternative_sum<long long, int, long>(i, lng);

    cout << val2 << endl;
    return 0; //
}

template <typename T1, typename T2, typename T3> T3 alternative_sum(T2 v1, T1 v2) {
    return v1 + v2; //
}
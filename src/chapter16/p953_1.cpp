#include <iostream>
#include <utility>

using namespace std;

template <typename F, typename T1, typename T2> //
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1)); //
}

void g(int &&i, int &j) {
    cout << i << " " << j << endl; //
}

int main(int argc, char *argv[]) {
    int i = 1;
    flip(g, i, 42);
    return 0; //
}
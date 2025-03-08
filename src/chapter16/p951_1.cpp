#include <iostream>

using namespace std;

template <typename F, typename T1, typename T2> //
void flip2(F f, T1 &&t1, T2 &&t2) {
    f(t2, t1); //
}

// p952_1
void g(int &&i, int &j) {
    cout << i << " " << j << endl; //
}

int main(int argc, char *argv[]) {
    // int i = 1;
    // p952_2
    // flip2(g, i, 42); // error: can't initialize int&& from an lvalue
    return 0; //
}
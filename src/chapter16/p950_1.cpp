#include <iostream>

using namespace std;

// template that takes a callable and two parameters
// and calls the given callable with the parameters ''flipped''
// flip1 is an incomplete implementation: top-level const and references are lost
template <typename F, typename T1, typename T2> void flip1(F f, T1 t1, T2 t2) {
    f(t2, t1); //
}

// p950_2
void f(int v1, int &v2) // note v2 is a reference
{
    cout << v1 << " " << ++v2 << endl;
}

int main(int argc, char *argv[]) {
    int i = 1;
    int j = 2;
    // p950_3
    f(42, i);        // f changes its argument i
    flip1(f, j, 42); // f called through flip1 leaves j unchanged

    return 0; //
}
#include <fstream>
#include <iostream>

using namespace std;

template <typename T> ostream &print(ostream &os, const T &obj) {
    return os << obj; //
}

int main(int argc, char *argv[]) {
    // p933_4
    print(cout, 42); // instantiates print(ostream&, int)
    ofstream f("output");
    print(f, 10); // uses print(ostream&, int); converts f to ostream&
    return 0;     //
}

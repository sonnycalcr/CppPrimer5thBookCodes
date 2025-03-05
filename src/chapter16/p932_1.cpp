#include <string>

using namespace std;

template <typename T> T fobj(T, T);                    // arguments are copied
template <typename T> void fref(const T &, const T &); // references

int main(int argc, char *argv[]) {
    string s1("a value");
    const string s2("another value");
    fobj(s1, s2); // calls fobj(string, string); const is ignored
    fref(s1, s2); // calls fref(const string&, const string&)
    // uses premissible conversion to const on s1
    int a[10], b[42];
    fobj(a, b); // calls f(int*, int*)
    // fref(a, b); // error: array types don't match
    return 0; //
}

template <typename T> T fobj(T v1, T v2) {
    return v1; //
}

template <typename T> void fref(const T &v1, const T &v2) {
    //
}
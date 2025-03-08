#include <iostream>
#include <string>

using namespace std;

template <typename T> int compare(const T &, const T &);
template <typename T> int compare(const T &a, const T &b) {
    if (a < b)
        return -1;
    if (b < a)
        return 1;
    return 0;
}

// pf1 points to the instantiation int compare(const int&, const int&)
int (*pf1)(const int &, const int &) = compare;

int main(int argc, char *argv[]) {
    // p942_1
    // overloaded versions of func; each takes a different function pointer type
    void func(int (*)(const string &, const string &));
    void func(int (*)(const int &, const int &));
    // func(compare); // error: which instantiation of compare?

    // ok: explicitly specify which version of compare to instantiate
    func(compare<int>); // passing compare(const int&, const int&)

    return 0; //
}

void func(int (*)(const string &, const string &)) {
    cout << "Called func with string comparison" << endl; //
}

void func(int (*)(const int &, const int &)) {
    cout << "Called func with int comparison" << endl; //
}
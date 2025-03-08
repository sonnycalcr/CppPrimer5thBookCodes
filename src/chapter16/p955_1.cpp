#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// print any type we don't otherwise handle
template <typename T> string debug_rep(const T &t) {
    ostringstream ret; // see § 8.3 (p. 321)
    ret << t;          // uses T's output operator to print a representation of t
    return ret.str();  // return a copy of the string to which ret is bound
}

// p955_2
// print pointers as their pointer value, followed by the object to which the pointer points
// NB: this function will not work properly with char*; see § 16.3 (p. 698)
template <typename T> string debug_rep(T *p) {
    ostringstream ret;
    ret << "pointer: " << p; // print the pointer's own value
    if (p)
        ret << " " << debug_rep(*p); // print the value to which p points
    else
        ret << " null pointer"; // or indicate that the p is null
    return ret.str();           // return a copy of the string to which ret is bound
}

// p957_1
// print strings inside double quotes
string debug_rep(const string &s) {
    return '"' + s + '"'; //
}

// p958_2
// convert the character pointers to string and call the string version of debug_rep
string debug_rep(char *p) {
    return debug_rep(string(p)); //
}
string debug_rep(const char *p) {
    return debug_rep(string(p)); //
}

int main(int argc, char *argv[]) {
    // p955_3
    string s("hi");
    cout << debug_rep(s) << endl;

    // p956_1
    cout << debug_rep(&s) << endl;

    // p956_2
    const string *sp = &s;
    cout << debug_rep(sp) << endl;

    // p957_2
    string s2("hi");
    cout << debug_rep(s2) << endl;

    // p958_1
    cout << debug_rep("hi world!") << endl; // calls debug_rep(T*)

    return 0; //
}
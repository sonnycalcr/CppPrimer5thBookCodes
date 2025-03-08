#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T> string debug_rep(const T &t);
template <typename T> string debug_rep(T *p);
// the following declaration must be in scope
// for the definition of debug_rep(char*) to do the right thing
string debug_rep(const string &);
string debug_rep(char *p) {
    // if the declaration for the version that takes a const string& is not in scope
    // the return will call debug_rep(const T&) with T instantiated to string
    return debug_rep(string(p));
}

int main(int argc, char *argv[]) {
    cout << debug_rep("hi world!") << endl; // calls debug_rep(T*)

    return 0; //
}

// print any type we don't otherwise handle
template <typename T> string debug_rep(const T &t) {
    ostringstream ret; // see § 8.3 (p. 321)
    ret << t;          // uses T's output operator to print a representation of t
    return ret.str();  // return a copy of the string to which ret is bound
}

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

// print strings inside double quotes
string debug_rep(const string &s) {
    return '"' + s + '"'; //
}
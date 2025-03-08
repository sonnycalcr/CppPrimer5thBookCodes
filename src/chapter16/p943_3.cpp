template <typename T> void f2(const T &); // can take an rvalue

int main(int argc, char *argv[]) {
    int i = 0;
    const int ci = 1;

    // parameter in f2 is const &; const in the argument is irrelevant
    // in each of these three calls, f2's function parameter is inferred as const int&
    f2(i);    // i is an int; template parameter T is int
    f2(ci);   // ci is a const int, but template parameter T is int
    f2(5);    // a const & parameter can be bound to an rvalue; T is int
    return 0; //
}
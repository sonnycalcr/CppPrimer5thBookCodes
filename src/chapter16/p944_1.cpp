template <typename T> void f3(T &&);

int main(int argc, char *argv[]) {
    f3(42); // argument is an rvalue of type int; template parameter T is int

    int i = 0;
    const int ci = 1;
    // p945_1
    f3(i);  // argument is an lvalue; template parameter T is int&
    f3(ci); // argument is an lvalue; template parameter T is const int&

    // p945_2
    // invalid code, for illustration purposes only
    // void f3<int&>(int& &&); // when T is int&, function parameter is int& &&

    // p945_3
    // void f3<int&>(int&); // when T is int&, function parameter collapses to int&
    return 0; //
}
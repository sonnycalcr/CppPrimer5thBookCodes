template <typename T> void f1(T &); // argument must be an lvalue

int main(int argc, char *argv[]) {
    int i = 0;
    const int ci = 2;

    // calls to f1 use the referred-to type of the argument as the template parameter type
    f1(i);  // i is an int; template parameter T is int
    f1(ci); // ci is a const int; template parameter T is const int
    // f1(5);    // error: argument to a & parameter must be an lvalue
    return 0; //
}

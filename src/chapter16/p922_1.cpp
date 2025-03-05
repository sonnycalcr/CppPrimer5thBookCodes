#include <iostream>

// function-object class that calls delete on a given pointer
class DebugDelete {
  public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    // as with any function template, the type of T is deduced by the compiler
    template <typename T> void operator()(T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }

  private:
    std::ostream &os;
};

int main(int argc, char *argv[]) {
    double *p = new double;

    DebugDelete d; // an object that can act like a delete expression
    d(p);          // calls DebugDelete::operator()(double*), which deletes p
    int *ip = new int;
    // calls operator()(int*) on a temporary DebugDelete object
    DebugDelete()(ip);
    return 0; //
}
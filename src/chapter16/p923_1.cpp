#include <iostream>
#include <memory>

using namespace std;

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
    // destroying the the object to which p points
    // instantiates DebugDelete::operator()<int>(int *)
    unique_ptr<int, DebugDelete> p(new int, DebugDelete());
    // destroying the the object to which sp points
    // instantiates DebugDelete::operator()<string>(string*)
    unique_ptr<string, DebugDelete> sp(new string, DebugDelete());

    return 0; //
}

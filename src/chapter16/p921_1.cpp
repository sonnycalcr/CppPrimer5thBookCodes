#include <iostream>
template <class T = int> class Numbers { // by default T is int
  public:
    Numbers(T v = 0) : val(v) {}
    T getVal() const { return this->val; }
    // various operations on numbers
  private:
    T val;
};

int main(int argc, char *argv[]) {
    Numbers<long double> lots_of_precision{12.0};
    Numbers<> average_precision; // empty <> says we want the default type
    std::cout << lots_of_precision.getVal() << std::endl;
    std::cout << average_precision.getVal() << std::endl;
    return 0; //
}
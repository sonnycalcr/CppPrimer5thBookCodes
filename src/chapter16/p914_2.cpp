#include <cstddef>
#include <iostream>
#include <string>

template <typename T> class Foo {
  public:
    static std::size_t count() { return ctr; }
    static void set_count(std::size_t n) { ctr = n; }
    // other interface members
  private:
    static std::size_t ctr;
    // other implementation members
};

template <typename T> std::size_t Foo<T>::ctr = 0;

int main(int argc, char *argv[]) {
    Foo<int>::set_count(12);
    std::cout << Foo<int>::count() << std::endl;

    // p914_3
    // instantiates static members Foo<string>::ctr and Foo<string>::count
    Foo<std::string> fs;
    // all three objects share the same Foo<int>::ctr and Foo<int>::count members
    Foo<int> fi, fi2, fi3;
    std::cout << fs.count() << std::endl;
    std::cout << fi.count() << std::endl;
    std::cout << fi2.count() << std::endl;
    std::cout << fi3.count() << std::endl;

    return 0; //
}
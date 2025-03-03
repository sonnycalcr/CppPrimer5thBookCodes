#include <iostream>

// Bar 模板类
template <typename Type> class Bar {
    friend Type;

  private:
    int secret = 42;

  public:
    void show() const { std::cout << "Bar's public view: " << secret << std::endl; }
};

class Foo {
  public:
    void accessBar(class Bar<Foo> &b) { std::cout << "Foo accessing Bar's private data: " << b.secret << std::endl; }
};

int main() {
    Bar<Foo> bar;
    Foo foo;

    bar.show();
    foo.accessBar(bar);

    return 0;
}
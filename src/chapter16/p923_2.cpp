#include <iostream>
#include <list>
#include <memory>
#include <vector>

using namespace std;

template <typename T> class Blob {
  public:
    template <typename It> Blob(It b, It e);

    std::shared_ptr<std::vector<T>> getData() const { return this->data; }

  private:
    std::shared_ptr<std::vector<T>> data;
};

// p923_3
template <typename T>  // type parameter for the class
template <typename It> // type parameter for the constructor
Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}

int main(int argc, char *argv[]) {
    // p924_1
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<const char *> w = {"now", "is", "the", "time"};
    // instantiates the Blob<int> class

    // and the Blob<int> constructor that has two int* parameters
    Blob<int> a1(begin(ia), end(ia));
    // instantiates the Blob<int> constructor that has
    // two vector<long>::iterator parameters
    Blob<int> a2(vi.begin(), vi.end());
    // instantiates the Blob<string> class and the Blob<string>
    // constructor that has two (list<const char*>::iterator parameters
    Blob<string> a3(w.begin(), w.end());

    std::cout << a1.getData()->front() << std::endl;
    std::cout << a1.getData()->back() << std::endl;
    return 0; //
}
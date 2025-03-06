#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T> class Blob {
  public:
    template <typename It> Blob(It b, It e);
    Blob(std::initializer_list<T> il);

    typename std::vector<T>::iterator begin() { return data->begin(); }
    typename std::vector<T>::iterator end() { return data->end(); }

    typename std::vector<T>::const_iterator begin() const { return data->begin(); }
    typename std::vector<T>::const_iterator end() const { return data->end(); }

    std::shared_ptr<std::vector<T>> getData() const { return this->data; }

  private:
    std::shared_ptr<std::vector<T>> data;
};

// p923_3
template <typename T>  // type parameter for the class
template <typename It> // type parameter for the constructor
Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}

template <typename T> // type parameter for the class
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

// p938_2
// a trailing return lets us declare the return type after the parameter list is seen
template <typename It> auto fcn(It beg, It end) -> decltype(*beg) {
    // process the range
    return *beg; // return a reference to an element from the range
}

int main(int argc, char *argv[]) {
    vector<int> vi = {1, 2, 3, 4, 5};
    Blob<string> ca = {"hi", "bye"};
    auto &i = fcn(vi.begin(), vi.end()); // fcn should return int&
    auto &s = fcn(ca.begin(), ca.end()); // fcn should return string&
    cout << i << ", " << s << endl;
    return 0; //
}
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

template <typename T> class Blob {
  public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    // constructors
    Blob();
    Blob(std::initializer_list<T> il);

    // number of elements in the Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const T &t) { data->push_back(t); }
    // move version; see § 13.6.3 (p. 548)
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();

    // element access
    T &back();
    T &operator[](size_type i); // defined in § 14.5 (p. 566)

  private:
    std::shared_ptr<std::vector<T>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

int main(int argc, char *argv[]) {
    Blob<int> ia;                         // empty Blob<int>
    Blob<int> ia2 = {0, 1, 2, 3, 4};      // Blob<int> with five elements
    std::cout << ia.size() << std::endl;  //
    std::cout << ia2.size() << std::endl; //

    // these definitions instantiate two distinct Blob types
    Blob<std::string> names;                 // Blob that holds strings
    Blob<double> prices;                     // different element type
    std::cout << names.size() << std::endl;  //
    std::cout << prices.size() << std::endl; //

    Blob<std::string> articles = {"a", "an", "the"};
    std::cout << articles[2] << std::endl;

    // instantiates Blob<int> and the initializer_list<int> constructor
    Blob<int> squares = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << squares.size() << std::endl;

    // instantiates Blob<int>::size() const
    for (size_t i = 0; i != squares.size(); ++i)
        squares[i] = i * i; // instantiates Blob<int>::operator[](size_t)
    std::cout << squares[2] << std::endl;

    return 0; //
}

template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T> T &Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> T &Blob<T>::operator[](size_type i) {
    // if i is too big, check will throw, preventing access to a nonexistent element
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T> Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T> Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}
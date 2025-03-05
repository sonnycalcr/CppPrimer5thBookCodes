#include <functional>
#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    // friend declarations for nonmember Sales_data operations added
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

  public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    explicit Sales_data(const std::string &s) : bookNo(s) {}
    explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); }
    // remaining members as before
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

  private:
    double avg_price() const { return units_sold ? revenue / units_sold : 0; }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of ''this'' object
    return *this;                 // return the object on which the function was called
}

// input transactions contain ISBN, number of copies sold, and sales price
istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum.combine(rhs);     // add data members from rhs into sum
    return sum;
}

// compare has a default template argument, less<T>
// and a default function argument, F()
template <typename T, typename F = less<T>> int compare(const T &v1, const T &v2, F f = F()) {
    if (f(v1, v2))
        return -1;
    if (f(v2, v1))
        return 1;
    return 0;
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);

int main(int argc, char *argv[]) {
    // p920_1
    bool i = compare(0, 42); // uses less; i is -1
    // result depends on the isbns in item1 and item2
    Sales_data item1(cin), item2(cin);
    bool j = compare(item1, item2, compareIsbn);
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    return 0; //
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn(); //
}
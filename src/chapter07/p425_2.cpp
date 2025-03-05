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

int main(int argc, char *argv[]) {
    Sales_data obj{"1234"};
    std::cout << obj.isbn() << std::endl;

    return 0; //
}
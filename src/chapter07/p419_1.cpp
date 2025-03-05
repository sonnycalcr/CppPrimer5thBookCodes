#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    // friend declarations for nonmember Sales_data operations added
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

  public:
    // nondelegating constructor initializes members from corresponding arguments
    Sales_data(std::string s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt * price) {}
    // remaining constructors all delegate to another constructor
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(std::string s) : Sales_data(s, 0, 0) {}
    Sales_data(std::istream &is) : Sales_data() { read(is, *this); }
    // other members as before
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

int main(int argc, char *argv[]) {
    // p368_1
    Sales_data total; // variable to hold the running sum

    if (read(cin, total)) {                     // read the first transaction
        Sales_data trans;                       // variable to hold data for the next transaction
        while (read(cin, trans)) {              // read the remaining transactions
            if (total.isbn() == trans.isbn()) { // check the isbns
                total.combine(trans);           // update the running total
            } else {
                print(cout, total) << endl; // print the results
                total = trans;              // process the next book
            }
        }
        print(cout, total) << endl;  // print the last transaction
    } else {                         // there was no input
        cerr << "No data?!" << endl; // notify the user
    }

    return 0; //
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

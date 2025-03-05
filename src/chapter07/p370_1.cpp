#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    // p380_1
    // constructors added
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &);

    // new members: operations on Sales_data objects
    // p371_2
    std::string isbn() const { return this->bookNo; }

    Sales_data &combine(const Sales_data &);
    double avg_price() const;
    // data members are unchanged from § 2.6.1 (p. 72)
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

// p373_1
double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

// p374_1
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of ''this'' object
    return *this;                 // return the object on which the function was called
}

// p383_1
Sales_data::Sales_data(std::istream &is) {
    read(is, *this); // read will read a transaction from is into this object
}

int main(int argc, char *argv[]) {
    // p368_1
    Sales_data total; // variable to hold the running sum

    if (read(cin, total)) {        // read the first transaction
        Sales_data trans;          // variable to hold data for the next transaction
        while (read(cin, trans)) { // read the remaining transactions
            //
            // p371_1
            //
            if (total.isbn() == trans.isbn()) { // check the isbns
                //
                // p374_2
                //
                total.combine(trans); // update the running total
            } else {
                print(cout, total) << endl; // print the results
                total = trans;              // process the next book
                //
                // p385_1
                // default assignment for Sales_data is equivalent to:
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        print(cout, total) << endl;  // print the last transaction
    } else {                         // there was no input
        cerr << "No data?!" << endl; // notify the user
    }

    return 0; //
}

// p376_1
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

// p376_2
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum.combine(rhs);     // add data members from rhs into sum
    return sum;
}

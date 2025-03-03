#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> int compare(const T &v1, const T &v2) {
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    string v1 = "123";
    string v2 = "456";
    cout << compare(v1, v2) << endl;
    double vv1 = 123.0;
    double vv2 = 456.0;
    cout << compare(vv1, vv2) << endl;

    cout << compare(1, 0) << endl; // T is int

    // instantiates int compare(const int&, const int&)
    cout << compare(1, 0) << endl; // T is int
    // initantiates int compare(const vector<int>&, const vector<int>&)
    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl; // T is vector<int>

    return 0;
}
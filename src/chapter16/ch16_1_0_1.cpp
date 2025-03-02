#include <iostream>
#include <string>

using namespace std;

// returns 0 if the values are equal, -1 if v1 is smaller, 1 if v2 is smaller
int compare(const string &v1, const string &v2) {
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;
    return 0;
}
int compare(const double &v1, const double &v2) {
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
    return 0;
}

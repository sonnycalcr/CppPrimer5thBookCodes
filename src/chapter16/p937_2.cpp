#include <iostream>

using namespace std;

template <typename T> int compare(const T &, const T &);

int main(int argc, char *argv[]) {
    long lng = 12;
    // compare(lng, 1024); // error: template parameters don't match
    int res1 = compare<long>(lng, 1024); // ok: instantiates compare(long, long)
    int res2 = compare<int>(lng, 1024);  // ok: instantiates compare(int, int)
    cout << res1 << ", " << res2 << endl;
    return 0; //
}

template <typename T> int compare(const T &v1, const T &v2) {
    return v1 < v2 ? -1 : 1; //
}
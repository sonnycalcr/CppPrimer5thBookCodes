#include <cstring>
#include <iostream>

using namespace std;

template <unsigned N, unsigned M> //
int compare(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2); //
}

template <unsigned N, unsigned M> //
int compare_size(const int (&p1)[N], const int (&p2)[M]) {
    return N > M ? 1 : -1; //
}

int main(int argc, char *argv[]) {
    cout << compare("hi", "mom") << endl;

    int p1[3] = {1, 2, 3};
    int p2[4] = {1, 2, 3, 4};
    cout << compare_size(p1, p2) << endl;

    return 0; //
}
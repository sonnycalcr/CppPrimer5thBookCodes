#include <iostream>
#include <utility>

using namespace std;

template <typename T> using twin = pair<T, T>;

int main(int argc, char *argv[]) {
    twin<string> authors; // authors is a pair<string, string>
    authors.first = "tom";
    authors.second = "jack";
    cout << authors.first << ", " << authors.second << endl;

    // p913_4
    twin<int> win_loss; // win_loss is a pair<int, int>
    twin<double> area;  // area is a pair<double, double>
    win_loss.first = 1;
    win_loss.second = 2;
    cout << win_loss.first << ", " << win_loss.second << endl;
    area.first = 12.0;
    area.second = 16.0;
    cout << "area is: " << area.first * area.second << endl;
    return 0; //
}
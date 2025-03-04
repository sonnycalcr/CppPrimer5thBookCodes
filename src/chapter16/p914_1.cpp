#include <iostream>
#include <string>

using namespace std;

template <typename T> using partNo = pair<T, unsigned>;

class Vehicle {
  public:
    string to_string() {
        return "Vehicle"; //
    }
};

class Student {
  public:
    string to_string() {
        return "Student"; //
    }
};

int main(int argc, char *argv[]) {
    partNo<string> books; // books is a pair<string, unsigned>
    cout << books.first.size() << endl;
    partNo<Vehicle> cars; // cars is a pair<Vehicle, unsigned>
    cout << cars.first.to_string() << endl;
    partNo<Student> kids; // kids is a pair<Student, unsigned
    cout << kids.first.to_string() << endl;

    return 0; //
}
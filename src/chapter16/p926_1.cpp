#include "./p926_0.hpp"

// Application.cc
// these template types must be instantiated elsewhere in the program
extern template class Blob<string>;
extern template int compare(const int &, const int &);
Blob<string> sa1, sa2; // instantiation will appear elsewhere
// Blob<int> and its initializer_list constructor instantiated in this file
Blob<int> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
Blob<int> a2(a1);              // copy constructor instantiated in this file
int i = compare(a1[0], a2[0]); // instantiation will appear elsewhere
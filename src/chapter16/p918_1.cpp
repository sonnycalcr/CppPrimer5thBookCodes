// all three uses of calc refer to the same function template
template <typename T> T calc(const T &, const T &); // declaration
template <typename U> U calc(const U &, const U &); // declaration
// definition of the template
template <typename Type> Type calc(const Type &a, const Type &b) { /* . . . */ }
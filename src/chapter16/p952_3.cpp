#include <utility>

template <typename T> void finalFcn(T &&arg) {
    //
}

template <typename Type> void forwardToFinalFcn(Type &&arg) {
    finalFcn(std::forward<Type>(arg));
    // ...
}
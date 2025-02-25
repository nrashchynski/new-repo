#include "fibonacci.h"

template <typename T>
std::vector<T> getFibonacciNumbers(int n) {
    std::vector<T> fibonacci;
    if (n <= 0) return fibonacci;

    fibonacci.push_back(0);
    if (n == 1) return fibonacci;

    fibonacci.push_back(1);
    for (int i = 2; i < n; ++i) {
        fibonacci.push_back(fibonacci[i - 1] + fibonacci[i - 2]);
    }
    return fibonacci;
}

template std::vector<int> getFibonacciNumbers<int>(int);

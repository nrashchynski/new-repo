#include <iostream>
#include <vector>
#include "fibonacci.h"

int main() {
    std::vector<int> expected = { 0, 1, 1, 2, 3 };
    std::vector<int> result = getFibonacciNumbers<int>(5);

    if (result != expected) {
        std::cerr << "TEST 1 FAILED: getFibonacciNumbers(5) returned incorrect result." << std::endl;
        return 1;
    }

    std::cout << "TEST 1 PASSED" << std::endl;
    return 0;
}
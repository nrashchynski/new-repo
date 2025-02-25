#include <iostream>
#include <vector>
#include "fibonacci.h"

int main() {
    std::vector<int> expected = {};
    std::vector<int> result = getFibonacciNumbers<int>(-1);

    if (result != expected) {
        std::cerr << "TEST 2 FAILED: getFibonacciNumbers(-1) did not return an empty vector." << std::endl;
        return 1;
    }

    std::cout << "TEST 2 PASSED" << std::endl;
    return 0;
}

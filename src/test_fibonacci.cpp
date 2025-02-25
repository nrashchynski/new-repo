#include <iostream>
#include <vector>
#include "fibonacci.h"

int main() {
    std::vector<int> expected = { 0, 1, 1, 2, 3 };
    std::vector<int> result = getFibonacciNumbers<int>(5);

    if (result == expected) {
        std::cout << "TEST PASSED" << std::endl;
        return 0; 
    }
    else {
        std::cerr << "TEST FAILED" << std::endl;
        return 1;
    }
}

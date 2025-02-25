#include <iostream>
#include <vector>
#include "fibonacci.h"

int main() {
    std::vector<int> wrongExpectation = { 0, 1, 2, 3, 5 }; // ������������ ��� ���������
    std::vector<int> result = getFibonacciNumbers<int>(5);

    if (result != wrongExpectation) {
        std::cerr << "TEST 3 FAILED: Unexpectedly matched incorrect Fibonacci sequence." << std::endl;
        return 1;
    }

    std::cout << "TEST 3 PASSED" << std::endl;
    return 0;
}

#include <iostream>
#include "fibonacci.h"
#include <clocale>


int main() {
    setlocale(LC_ALL, "Russian");

   /* std::cout << "������ ������...\n";
    runTests();*/

    try {
        int n;
        std::cout << "������� ���������� ����� ���������: ";
        std::cin >> n;

        std::vector<int> fibNumbers = getFibonacciNumbers<int>(n);

        std::cout << "������ " << n << " ����� ���������: ";
        for (int i = 0; i < fibNumbers.size(); ++i) {
            std::cout << fibNumbers[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }

    return 0;
}
#include <iostream>
#include "fibonacci.h"
#include <clocale>


int main() {
    setlocale(LC_ALL, "Russian");

   /* std::cout << "Запуск тестов...\n";
    runTests();*/

    try {
        int n;
        std::cout << "Введите количество чисел Фибоначчи: ";
        std::cin >> n;

        std::vector<int> fibNumbers = getFibonacciNumbers<int>(n);

        std::cout << "Первые " << n << " чисел Фибоначчи: ";
        for (int i = 0; i < fibNumbers.size(); ++i) {
            std::cout << fibNumbers[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
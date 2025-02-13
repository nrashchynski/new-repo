#include <iostream>
#include <vector>
#include <stdexcept>
#include <clocale>

template <typename T>
std::vector<T> getFibonacciNumbers(int n) {
    if (n < 0) {
        throw std::invalid_argument("n должно быть неотрицательным числом");
    }

    std::vector<T> result;

    if (n >= 1) {
        result.push_back(0);
    }
    if (n >= 2) {
        result.push_back(1);
    }

    for (int i = 2; i < n; ++i) {
        T next = result[i - 1] + result[i - 2];
        result.push_back(next);
    }

    return result;
}

template <typename T>
bool areVectorsEqual(const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

void runTests() {
    // Тест 1: n = 0
    {
        std::vector<int> result = getFibonacciNumbers<int>(0);
        std::vector<int> expected = {};
        if (areVectorsEqual(result, expected)) {
            std::cout << "Тест 1: PASSED\n";
        }
        else {
            std::cout << "Тест 1: FAILED\n";
        }
    }

    // Тест 2: n = 1
    {
        std::vector<int> result = getFibonacciNumbers<int>(1);
        std::vector<int> expected = { 0 };
        if (areVectorsEqual(result, expected)) {
            std::cout << "Тест 2: PASSED\n";
        }
        else {
            std::cout << "Тест 2: FAILED\n";
        }
    }

    // Тест 3: n = 2
    {
        std::vector<int> result = getFibonacciNumbers<int>(2);
        std::vector<int> expected = { 0, 1 };
        if (areVectorsEqual(result, expected)) {
            std::cout << "Тест 3: PASSED\n";
        }
        else {
            std::cout << "Тест 3: FAILED\n";
        }
    }

    // Тест 4: n = 5
    {
        std::vector<int> result = getFibonacciNumbers<int>(5);
        std::vector<int> expected = { 0, 1, 1, 2, 3 };
        if (areVectorsEqual(result, expected)) {
            std::cout << "Тест 4: PASSED\n";
        }
        else {
            std::cout << "Тест 4: FAILED\n";
        }
    }

    // Тест 5: n = -1 (ожидаем исключение)
    {
        try {
            std::vector<int> result = getFibonacciNumbers<int>(-1);
            std::cout << "Тест 5: FAILED (исключение не было выброшено)\n";
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Тест 5: PASSED\n";
        }
    }

    // Тест 6: n = 10
    {
        std::vector<int> result = getFibonacciNumbers<int>(10);
        std::vector<int> expected = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
        if (areVectorsEqual(result, expected)) {
            std::cout << "Тест 6: PASSED\n";
        }
        else {
            std::cout << "Тест 6: FAILED\n";
        }
    }

    // Тест 7: n = 10 с типом double
    {
        std::vector<double> result = getFibonacciNumbers<double>(10);
        std::vector<double> expected = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
        if (areVectorsEqual(result, expected)) {
            std::cout << "Тест 7: PASSED\n";
        }
        else {
            std::cout << "Тест 7: FAILED\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Запуск тестов...\n";
    runTests();

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
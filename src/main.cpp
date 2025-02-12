#include <iostream>
#include <vector>
#include <stdexcept>
#include <clocale>

std::vector<int> getFibonacciNumbers(int n) {
    if (n < 0) {
        throw std::invalid_argument("n ������ ���� ��������������� ������");
    }

    std::vector<int> result;

    if (n >= 1) {
        result.push_back(0);
    }
    if (n >= 2) {
        result.push_back(1);
    }

    for (int i = 2; i < n; ++i) {
        int next = result[i - 1] + result[i - 2];
        result.push_back(next);
    }

    return result;
}

bool areVectorsEqual(const std::vector<int>& v1, const std::vector<int>& v2) {
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
    // ���� 1: n = 0
    {
        std::vector<int> result = getFibonacciNumbers(0);
        std::vector<int> expected = {};
        if (areVectorsEqual(result, expected)) {
            std::cout << "���� 1: PASSED\n";
        }
        else {
            std::cout << "���� 1: FAILED\n";
        }
    }

    // ���� 2: n = 1
    {
        std::vector<int> result = getFibonacciNumbers(1);
        std::vector<int> expected = { 0 };
        if (areVectorsEqual(result, expected)) {
            std::cout << "���� 2: PASSED\n";
        }
        else {
            std::cout << "���� 2: FAILED\n";
        }
    }

    // ���� 3: n = 2
    {
        std::vector<int> result = getFibonacciNumbers(2);
        std::vector<int> expected = { 0, 1 };
        if (areVectorsEqual(result, expected)) {
            std::cout << "���� 3: PASSED\n";
        }
        else {
            std::cout << "���� 3: FAILED\n";
        }
    }

    // ���� 4: n = 5
    {
        std::vector<int> result = getFibonacciNumbers(5);
        std::vector<int> expected = { 0, 1, 1, 2, 3 };
        if (areVectorsEqual(result, expected)) {
            std::cout << "���� 4: PASSED\n";
        }
        else {
            std::cout << "���� 4: FAILED\n";
        }
    }

    // ���� 5: n = -1 (������� ����������)
    {
        try {
            std::vector<int> result = getFibonacciNumbers(-1);
            std::cout << "���� 5: FAILED (���������� �� ���� ���������)\n";
        }
        catch (const std::invalid_argument& e) {
            std::cout << "���� 5: PASSED\n";
        }
    }

    // ���� 6: n = 10
    {
        std::vector<int> result = getFibonacciNumbers(10);
        std::vector<int> expected = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
        if (areVectorsEqual(result, expected)) {
            std::cout << "���� 6: PASSED\n";
        }
        else {
            std::cout << "���� 6: FAILED\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ru");

    std::cout << "������ ������...\n";
    runTests();

    try {
        int n;
        std::cout << "������� ���������� ����� ���������: ";
        std::cin >> n;

        std::vector<int> fibNumbers = getFibonacciNumbers(n);

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
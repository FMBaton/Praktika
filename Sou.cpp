#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int M, N;

    // Шаг 1: Ввод размеров массивов
    std::cout << "Enter arrey A: ";
    std::cin >> M;

    std::cout << "Enter arrey B: ";
    std::cin >> N;

    // Шаг 2: Создание массивов A и B
    std::vector<int> A(M);
    std::vector<int> B(N);

    std::cout << "Введите элементы массива A:\n";
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::cout << "Введите элементы массива B:\n";
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    // Шаг 3: Создание пустого массива C
    std::vector<int> C;

    // Шаг 4: Нахождение общих элементов без повторений
    for (int i = 0; i < M; i++) {
        if (std::find(B.begin(), B.end(), A[i]) != B.end() &&
            std::find(C.begin(), C.end(), A[i]) == C.end()) {
            C.push_back(A[i]);
        }
    }

    // Шаг 5: Вывод результата
    std::cout << "Общие элементы массивов A и B без повторений: ";
    for (int i = 0; i < C.size(); i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

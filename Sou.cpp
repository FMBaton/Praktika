#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int M, N;
    std::cout << "Enter the size of array A: ";
    std::cin >> M;

    std::cout << "Enter the size of array B: ";
    std::cin >> N;

    std::vector<int> A(M);
    std::vector<int> B(N);
    std::unordered_set<int> commonElements;

    std::cout << "Enter elements of array A: ";
    for (int i = 0; i < M; ++i) {
        std::cin >> A[i];
    }

    std::cout << "Enter elements of array B: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    // Find common elements and store them in the set
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i] == B[j]) {
                commonElements.insert(A[i]);
                break;
            }
        }
    }

    // Convert set to vector for easy printing
    std::vector<int> C(commonElements.begin(), commonElements.end());

    // Print the common elements
    std::cout << "Common elements: ";
    for (int element : C) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

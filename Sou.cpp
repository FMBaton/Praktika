#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int M, N;

    // ��� 1: ���� �������� ��������
    std::cout << "Enter arrey A: ";
    std::cin >> M;

    std::cout << "Enter arrey B: ";
    std::cin >> N;

    // ��� 2: �������� �������� A � B
    std::vector<int> A(M);
    std::vector<int> B(N);

    std::cout << "������� �������� ������� A:\n";
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::cout << "������� �������� ������� B:\n";
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    // ��� 3: �������� ������� ������� C
    std::vector<int> C;

    // ��� 4: ���������� ����� ��������� ��� ����������
    for (int i = 0; i < M; i++) {
        if (std::find(B.begin(), B.end(), A[i]) != B.end() &&
            std::find(C.begin(), C.end(), A[i]) == C.end()) {
            C.push_back(A[i]);
        }
    }

    // ��� 5: ����� ����������
    std::cout << "����� �������� �������� A � B ��� ����������: ";
    for (int i = 0; i < C.size(); i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

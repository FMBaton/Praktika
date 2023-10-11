#include <iostream>

const int MAX_SIZE = 100; // ������������ ������ �����

struct FixedCapacityStack {
    int arr[MAX_SIZE];  // ������ ��� �������� ���������
    int top;            // ������ ������� �����

    // �����������: ������������� ������� �����
    FixedCapacityStack() : top(-1) {}

    // �������� �� �������
    bool isEmpty() const {
        return top == -1;
    }

    // �������� �� ������������
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    // ���������� �������� �� ������� �����
    void push(int value) {
        if (isFull()) {
            std::cout << "Stack overflow! Cannot push more elements.\n";
            return;
        }
        arr[++top] = value;
    }

    // ���������� �������� � ������� �����
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty! Cannot pop.\n";
            return -1; // ���������� -1 ��� ������� ������
        }
        return arr[top--];
    }

    // ��������� �������� � ������� ����� (��� ��������)
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty! Cannot peek.\n";
            return -1; // ���������� -1 ��� ������� ������
        }
        return arr[top];
    }
};

int main() {
    FixedCapacityStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << "\n";

    std::cout << "Popping elements:\n";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << "\n";
    }

    return 0;
}

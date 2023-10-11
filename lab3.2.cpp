#include <iostream>

// ��������� ��� ������������� ���� � ��������� ������
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

class Queue {
private:
    ListNode* front; // ��������� �� ������ �������
    ListNode* rear;  // ��������� �� ����� �������

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // �������� �� �������
    bool isEmpty() const {
        return front == nullptr;
    }

    // ���������� �������� � ����� �������
    void enqueue(int value) {
        ListNode* newNode = new ListNode(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // ���������� �������� �� ������ �������
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty! Cannot dequeue.\n";
            return -1; // ���������� -1 ��� ������� ������
        }
        int value = front->val;
        ListNode* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;  // ������������� rear � nullptr, ���� ������� ����� ������
        }
        return value;
    }

    // ��������� �������� �� ������ ������� (��� ��������)
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty! Cannot peek.\n";
            return -1; // ���������� -1 ��� ������� ������
        }
        return front->val;
    }

    ~Queue() {
        // ������� ������, ���������� ����
        while (front != nullptr) {
            ListNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr; // ������������� rear � nullptr
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.peek() << "\n";

    std::cout << "Dequeueing elements:\n";
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << "\n";
    }

    return 0;
}

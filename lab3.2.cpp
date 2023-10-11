#include <iostream>

// Структура для представления узла в связанном списке
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

class Queue {
private:
    ListNode* front; // Указатель на начало очереди
    ListNode* rear;  // Указатель на конец очереди

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Проверка на пустоту
    bool isEmpty() const {
        return front == nullptr;
    }

    // Добавление элемента в конец очереди
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

    // Извлечение элемента из начала очереди
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty! Cannot dequeue.\n";
            return -1; // Возвращаем -1 как признак ошибки
        }
        int value = front->val;
        ListNode* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;  // Устанавливаем rear в nullptr, если очередь стала пустой
        }
        return value;
    }

    // Получение элемента из начала очереди (без удаления)
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty! Cannot peek.\n";
            return -1; // Возвращаем -1 как признак ошибки
        }
        return front->val;
    }

    ~Queue() {
        // Очищаем память, освобождая узлы
        while (front != nullptr) {
            ListNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr; // Устанавливаем rear в nullptr
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

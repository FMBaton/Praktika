#include <iostream>

const int MAX_SIZE = 100; // Максимальный размер стека

struct FixedCapacityStack {
    int arr[MAX_SIZE];  // Массив для хранения элементов
    int top;            // Индекс вершины стека

    // Конструктор: инициализация пустого стека
    FixedCapacityStack() : top(-1) {}

    // Проверка на пустоту
    bool isEmpty() const {
        return top == -1;
    }

    // Проверка на переполнение
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    // Добавление элемента на вершину стека
    void push(int value) {
        if (isFull()) {
            std::cout << "Stack overflow! Cannot push more elements.\n";
            return;
        }
        arr[++top] = value;
    }

    // Извлечение элемента с вершины стека
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty! Cannot pop.\n";
            return -1; // Возвращаем -1 как признак ошибки
        }
        return arr[top--];
    }

    // Получение элемента с вершины стека (без удаления)
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty! Cannot peek.\n";
            return -1; // Возвращаем -1 как признак ошибки
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

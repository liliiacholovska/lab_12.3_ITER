#include <iostream>

using namespace std;

struct Node {
    int data;   // Поле даних
    Node* prev; // Вказівник на попередній елемент у списку
    Node* next; // Вказівник на наступний елемент у списку
};

// Функція для створення двонаправленого списку з масиву значень
Node* createList(int values[], int size) {
    Node* head = nullptr; // Початок списку
    Node* tail = nullptr; // Кінець списку

    for (int i = 0; i < size; ++i) {
        Node* newNode = new Node();  // Створення нового вузла
        newNode->data = values[i];   // Встановлення значення
        newNode->prev = tail;        // Вказівник на попередній вузол
        newNode->next = nullptr;     // Наступний вузол відсутній

        if (tail) {
            tail->next = newNode;   // Встановлення вказівника на новий вузол як наступний за останнім
        }
        else {
            head = newNode;         // Якщо список був порожнім, новий вузол стає головою
        }
        tail = newNode;             // Оновлення останнього вузла
    }

    return head;                    // Повернення голови списку
}

// Функція для виведення усіх елементів списку
void printList(Node* head) {
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data << " "; // Вивід даних поточного вузла
    }
    cout << endl; // Перехід на новий рядок після виведення списку
}

// Функція для обміну сусідніх елементів у списку
void swapAdjacentNodes(Node*& head) {
    Node* current = head; // Початковий елемент для обміну
    if (current == nullptr || current->next == nullptr) {
        return; // Повернення з функції, якщо в списку менше двох елементів
    }

    Node* next = current->next; // Другий елемент для обміну
    current->next = next->next; // Перенаправлення вказівника на наступний елемент за другим
    next->next = current;       // Перенаправлення вказівника другого елемента на перший
    next->prev = current->prev; // Перенаправлення вказівника на попередній елемент для другого елемента
    current->prev = next;       // Встановлення другого елемента як попереднього для першого

    if (current->next) {
        current->next->prev = current; // Встановлення першого елемента як попереднього для наступного після них
    }
    head = next; // Оновлення голови списку

    Node* prev = current; // Вузол перед наступною парою для обміну
    current = current->next; // Перехід до наступної пари
    // Проходимо через список, поки поточний вузол і наступний вузол існують
    while (current && current->next) {
        next = current->next;           // Збереження наступного вузла для обміну
        current->next = next->next;     // Перенаправлення вказівника на наступний вузол поточного на вузол після next
        next->next = current;           // Перенаправлення вказівника на наступний вузол next на поточний вузол
        next->prev = prev;              // Встановлення вказівника на попередній вузол next як prev
        current->prev = next;           // Встановлення вказівника на попередній вузол поточного як next
        prev->next = next;              // Перенаправлення вказівника на наступний вузол prev на next

        // Якщо у поточного вузла є наступний вузол після обміну, встановлення поточного вузла як попереднього для цього вузла
        if (current->next) {
            current->next->prev = current;
        }

        prev = current;                 // Оновлення prev до поточного вузла, який тепер стає попереднім перед наступною парою для обміну
        current = current->next;        // Перехід до наступної пари вузлів для обміну
    }
}

// Функція для видалення списку і звільнення пам'яті
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;   // Зберігання поточного вузла для видалення
        head = head->next;   // Перехід до наступного вузла
        delete temp;         // Звільнення пам'яті поточного вузла
    }
}

int main() {
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(values) / sizeof(values[0]); // Обчислення кількості елементів у масиві

    Node* head = createList(values, size); // Створення списку

    cout << "Original list:" << endl;
    printList(head); // Виведення оригінального списку

    swapAdjacentNodes(head); // Виконання обміну сусідніх елементів

    cout << "List after swapping adjacent nodes:" << endl;
    printList(head); // Виведення списку після обміну

    deleteList(head); // Видалення списку та звільнення пам'яті
    return 0;
}
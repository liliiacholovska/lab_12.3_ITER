#include <iostream>

using namespace std;

struct Node {
    int data;   // ���� �����
    Node* prev; // �������� �� ��������� ������� � ������
    Node* next; // �������� �� ��������� ������� � ������
};

// ������� ��� ��������� ��������������� ������ � ������ �������
Node* createList(int values[], int size) {
    Node* head = nullptr; // ������� ������
    Node* tail = nullptr; // ʳ���� ������

    for (int i = 0; i < size; ++i) {
        Node* newNode = new Node();  // ��������� ������ �����
        newNode->data = values[i];   // ������������ ��������
        newNode->prev = tail;        // �������� �� ��������� �����
        newNode->next = nullptr;     // ��������� ����� �������

        if (tail) {
            tail->next = newNode;   // ������������ ��������� �� ����� ����� �� ��������� �� �������
        }
        else {
            head = newNode;         // ���� ������ ��� �������, ����� ����� ��� �������
        }
        tail = newNode;             // ��������� ���������� �����
    }

    return head;                    // ���������� ������ ������
}

// ������� ��� ��������� ��� �������� ������
void printList(Node* head) {
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data << " "; // ���� ����� ��������� �����
    }
    cout << endl; // ������� �� ����� ����� ���� ��������� ������
}

// ������� ��� ����� ������ �������� � ������
void swapAdjacentNodes(Node*& head) {
    Node* current = head; // ���������� ������� ��� �����
    if (current == nullptr || current->next == nullptr) {
        return; // ���������� � �������, ���� � ������ ����� ���� ��������
    }

    Node* next = current->next; // ������ ������� ��� �����
    current->next = next->next; // ��������������� ��������� �� ��������� ������� �� ������
    next->next = current;       // ��������������� ��������� ������� �������� �� ������
    next->prev = current->prev; // ��������������� ��������� �� ��������� ������� ��� ������� ��������
    current->prev = next;       // ������������ ������� �������� �� ������������ ��� �������

    if (current->next) {
        current->next->prev = current; // ������������ ������� �������� �� ������������ ��� ���������� ���� ���
    }
    head = next; // ��������� ������ ������

    Node* prev = current; // ����� ����� ��������� ����� ��� �����
    current = current->next; // ������� �� �������� ����
    // ��������� ����� ������, ���� �������� ����� � ��������� ����� �������
    while (current && current->next) {
        next = current->next;           // ���������� ���������� ����� ��� �����
        current->next = next->next;     // ��������������� ��������� �� ��������� ����� ��������� �� ����� ���� next
        next->next = current;           // ��������������� ��������� �� ��������� ����� next �� �������� �����
        next->prev = prev;              // ������������ ��������� �� ��������� ����� next �� prev
        current->prev = next;           // ������������ ��������� �� ��������� ����� ��������� �� next
        prev->next = next;              // ��������������� ��������� �� ��������� ����� prev �� next

        // ���� � ��������� ����� � ��������� ����� ���� �����, ������������ ��������� ����� �� ������������ ��� ����� �����
        if (current->next) {
            current->next->prev = current;
        }

        prev = current;                 // ��������� prev �� ��������� �����, ���� ����� ��� ��������� ����� ��������� ����� ��� �����
        current = current->next;        // ������� �� �������� ���� ����� ��� �����
    }
}

// ������� ��� ��������� ������ � ��������� ���'��
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;   // ��������� ��������� ����� ��� ���������
        head = head->next;   // ������� �� ���������� �����
        delete temp;         // ��������� ���'�� ��������� �����
    }
}

int main() {
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(values) / sizeof(values[0]); // ���������� ������� �������� � �����

    Node* head = createList(values, size); // ��������� ������

    cout << "Original list:" << endl;
    printList(head); // ��������� ������������ ������

    swapAdjacentNodes(head); // ��������� ����� ������ ��������

    cout << "List after swapping adjacent nodes:" << endl;
    printList(head); // ��������� ������ ���� �����

    deleteList(head); // ��������� ������ �� ��������� ���'��
    return 0;
}
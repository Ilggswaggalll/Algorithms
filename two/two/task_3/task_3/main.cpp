#include <iostream>
using namespace std;

// Структура для узла списка
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Класс кольцевого двусвязного списка
class CircularDoublyLinkedList {
private:
    Node* head;  // Указатель на первый элемент списка

public:
    // Конструктор
    CircularDoublyLinkedList() : head(nullptr) {}

    // Функция добавления узла в конец кольцевого списка
    void addNodeToEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            // Если список пустой, новый узел указывает на сам себя
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            // Вставляем новый узел в конец списка
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // Функция удаления узла по значению
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->data == value) {
                // Если узел единственный
                if (current->next == current) {
                    delete current;
                    head = nullptr;
                    return;
                }

                // Если узел не единственный
                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == head) {
                    head = current->next;
                }

                delete current;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Элемент не найден." << endl;
    }

    // Функция вывода элементов кольцевого списка
    void printList() {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Функция проверки, является ли список кольцевым
    bool isCircular() {
        if (head == nullptr) return false;

        Node* current = head;
        do {
            current = current->next;
        } while (current != head && current != nullptr);

        return current == head;
    }

    // Деструктор для освобождения памяти
    ~CircularDoublyLinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        do {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

// Основная программа
int main() {
    CircularDoublyLinkedList list;

    // Добавление узлов
    list.addNodeToEnd(1);
    list.addNodeToEnd(2);
    list.addNodeToEnd(3);
    list.addNodeToEnd(4);
    cout << "Список после добавления узлов: ";
    list.printList();

    // Проверка, является ли список кольцевым
    cout << "Является ли список кольцевым? " << (list.isCircular() ? "Да" : "Нет") << endl;

    // Удаление узлов
    list.deleteNode(2);
    cout << "Список после удаления узла со значением 2: ";
    list.printList();

    // Удаление последнего элемента
    list.deleteNode(4);
    cout << "Список после удаления узла со значением 4: ";
    list.printList();

    list.deleteNode(1);
    list.deleteNode(3);
    cout << "Список после удаления всех элементов: ";
    list.printList();

    // Проверка, является ли список кольцевым
    cout << "Является ли список кольцевым? " << (list.isCircular() ? "Да" : "Нет") << endl;

    return 0;
}


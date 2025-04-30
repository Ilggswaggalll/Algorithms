#include <iostream>
using namespace std;

// Структура для узла списка
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Конструктор для удобства создания новых узлов
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Класс для кольцевого двусвязного списка
class DoublyCircularLinkedList {
private:
    Node* head;

public:
    // Конструктор
    DoublyCircularLinkedList() : head(nullptr) {}

    // Функция для добавления узла в конец списка
    void addNodeToEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // Функция для вставки нового узла перед узлом с указанным значением
    void insertBefore(int targetValue, int value) {
        Node* current = head;
        if (head) {
            do {
                if (current->data == targetValue) {
                    Node* newNode = new Node(value);
                    newNode->next = current;
                    newNode->prev = current->prev;
                    current->prev->next = newNode;
                    current->prev = newNode;
                    if (current == head) {
                        head = newNode;
                    }
                    return;
                }
                current = current->next;
            } while (current != head);
        }
        cout << "Значение " << targetValue << " не найдено в списке." << endl;
    }

    // Функция для удаления узла с заданным значением
    void deleteNode(int value) {
        if (!head) {
            cout << "Список пуст!" << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->data == value) {
                if (current->next == current) {
                    delete current;
                    head = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    if (current == head) {
                        head = current->next;
                    }
                    delete current;
                }
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Значение " << value << " не найдено в списке." << endl;
    }

    // Функция для подсчета количества узлов в списке
    int countNodes() {
        int count = 0;
        if (head) {
            Node* current = head;
            do {
                count++;
                current = current->next;
            } while (current != head);
        }
        return count;
    }

    // Функция для вывода списка в прямом порядке
    void printForward() {
        if (!head) {
            cout << "Список пуст!" << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Функция для вывода списка в обратном порядке
    void printBackward() {
        if (!head) {
            cout << "Список пуст!" << endl;
            return;
        }
        Node* current = head->prev;
        do {
            cout << current->data << " ";
            current = current->prev;
        } while (current != head->prev);
        cout << endl;
    }

    // Деструктор для освобождения памяти
    ~DoublyCircularLinkedList() {
        if (head) {
            Node* current = head;
            do {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != head);
        }
    }
};

int main() {
    DoublyCircularLinkedList list;

    // Пример добавления узлов
    list.addNodeToEnd(10);
    list.addNodeToEnd(20);
    list.addNodeToEnd(30);
    list.addNodeToEnd(40);

    cout << "Список в прямом порядке: ";
    list.printForward();

    cout << "Список в обратном порядке: ";
    list.printBackward();

    // Вставка перед узлом
    list.insertBefore(30, 25);

    cout << "После вставки 25 перед 30:" << endl;
    cout << "Список в прямом порядке: ";
    list.printForward();

    // Удаление узла
    list.deleteNode(20);

    cout << "После удаления 20:" << endl;
    cout << "Список в прямом порядке: ";
    list.printForward();

    cout << "Количество узлов в списке: " << list.countNodes() << endl;

    return 0;
}


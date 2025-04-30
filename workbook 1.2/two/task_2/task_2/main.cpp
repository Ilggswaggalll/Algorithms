#include <iostream>

struct Node {
    int data;
    Node* next;
};

void splitList(Node* head, int x, Node*& lessList, Node*& greaterList) {
    // Инициализация головных узлов двух новых списков
    lessList = nullptr;
    greaterList = nullptr;

    // Указатели для конечных узлов новых списков
    Node* lessTail = nullptr;
    Node* greaterTail = nullptr;

    // Проходим по исходному списку
    while (head != nullptr) {
        if (head->data < x) {
            // Если значение меньше X, добавляем в первый список
            if (lessList == nullptr) {
                // Если список пуст, устанавливаем голову
                lessList = head;
                lessTail = head;
            } else {
                // В противном случае добавляем в конец
                lessTail->next = head;
                lessTail = lessTail->next;
            }
        } else {
            // Если значение больше или равно X, добавляем во второй список
            if (greaterList == nullptr) {
                // Устанавливаем голову второго списка
                greaterList = head;
                greaterTail = head;
            } else {
                // Добавляем в конец второго списка
                greaterTail->next = head;
                greaterTail = greaterTail->next;
            }
        }
        // Переход к следующему узлу
        head = head->next;
    }

    // Завершаем списки, устанавливая последний элемент в nullptr
    if (lessTail) lessTail->next = nullptr;
    if (greaterTail) greaterTail->next = nullptr;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Пример списка 3 -> 5 -> 2 -> 8 -> 1 -> nullptr
    Node* head = new Node;
    head->data = 3;
    head->next = new Node;
    head->next->data = 5;
    head->next->next = new Node;
    head->next->next->data = 2;
    head->next->next->next = new Node;
    head->next->next->next->data = 8;
    head->next->next->next->next = new Node;
    head->next->next->next->next->data = 1;
    head->next->next->next->next->next = nullptr;

    // Считываем значение X
    int x;
    std::cout << "Введите значение X: ";
    std::cin >> x;

    Node* lessList = nullptr;
    Node* greaterList = nullptr;

    // Разделяем список
    splitList(head, x, lessList, greaterList);

    // Выводим результаты
    std::cout << "Список со значениями меньше " << x << ": ";
    printList(lessList);
    std::cout << "Список со значениями больше или равными " << x << ": ";
    printList(greaterList);

    // Освобождение памяти
    deleteList(head); // Освобождаем исходный список
    deleteList(lessList); // Освобождаем список с меньшими значениями
    deleteList(greaterList); // Освобождаем список с большими или равными значениями

    return 0;
}

struct Node {
    int data;
    Node* next;
};

bool hasNoExtraLinks(Node* head) {
    if (head == nullptr) {
        return true; // Пустой список считается правильным
    }

    // Инициализация двух указателей
    Node* slow = head;
    Node* fast = head;

    // Перемещение указателей
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;             // Медленный указатель на следующий элемент
        fast = fast->next->next;      // Быстрый указатель на элемент через один

        // Если при движении быстрый указатель достигнет медленного, есть цикл
        if (slow == fast) {
            return false; // Цикл найден, значит есть «лишние» ссылки
        }
    }

    // Если цикл не найден и fast указатель достиг конца списка, то списка корректен
    return true;
}


#include <iostream>

void testList(Node* head, bool expected) {
    bool result = hasNoExtraLinks(head);
    std::cout << (result == expected ? "Passed" : "Failed") << std::endl;
}

// Пример конструкций тестов
int main() {
    // Пустой список
    testList(nullptr, true);

    // Список без циклов
    Node* head1 = new Node{1, new Node{2, new Node{3, nullptr}}};
    testList(head1, true);

    // Список с циклом
    Node* nodeCyclic1 = new Node{1, new Node{2, new Node{3, nullptr}}};
    nodeCyclic1->next->next->next = nodeCyclic1->next; // 3 -> 2
    testList(nodeCyclic1, false);

    // Список с перескоками
    Node* nodeJump1 = new Node{1, new Node{2, new Node{3, nullptr}}};
    nodeJump1->next->next->next = nodeJump1; // 3 -> 1
    testList(nodeJump1, false);

    // Сложный случай с циклом
    Node* head2 = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, nullptr}}}}};
    head2->next->next->next->next->next = head2->next->next; // 5 -> 3
    testList(head2, false);

    // Список из одного узла
    Node* headSingle = new Node{1, nullptr};
    testList(headSingle, true);

    // Освобождение памяти (не забудьте)
    //...

    return 0;
}
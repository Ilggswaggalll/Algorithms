#include <iostream>

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
        slow = slow->next;            // Медленный указатель на следующий элемент
        fast = fast->next->next;      // Быстрый указатель на элемент через один

        // Если при движении быстрый указатель достигнет медленного, есть цикл
        if (slow == fast) {
            return false; // Цикл найден, значит есть «лишние» ссылки
        }
    }

    // Если цикл не найден и fast указатель достиг конца списка, то списка корректен
    return true;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void testList(Node* head, bool expected) {
    bool result = hasNoExtraLinks(head);
    std::cout << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main() {
    // Пустой список
    testList(nullptr, true);
    
    // Список без циклов
    Node* head1 = new Node;
    head1->data = 1;
    head1->next = new Node;
    head1->next->data = 2;
    head1->next->next = new Node;
    head1->next->next->data = 3;
    head1->next->next->next = nullptr;
    testList(head1, true);
    
    // Список с циклом
    Node* nodeCyclic1 = new Node;
    nodeCyclic1->data = 1;
    nodeCyclic1->next = new Node;
    nodeCyclic1->next->data = 2;
    nodeCyclic1->next->next = new Node;
    nodeCyclic1->next->next->data = 3;
    nodeCyclic1->next->next->next = nodeCyclic1->next; // 3 -> 2
    testList(nodeCyclic1, false);
    
    // Список с перескоками
    Node* nodeJump1 = new Node;
    nodeJump1->data = 1;
    nodeJump1->next = new Node;
    nodeJump1->next->data = 2;
    nodeJump1->next->next = new Node;
    nodeJump1->next->next->data = 3;
    nodeJump1->next->next->next = nodeJump1; // 3 -> 1
    testList(nodeJump1, false);
    
    // Сложный случай с циклом
    Node* head2 = new Node;
    head2->data = 1;
    head2->next = new Node;
    head2->next->data = 2;
    head2->next->next = new Node;
    head2->next->next->data = 3;
    head2->next->next->next = new Node;
    head2->next->next->next->data = 4;
    head2->next->next->next->next = new Node;
    head2->next->next->next->next->data = 5;
    head2->next->next->next->next->next = head2->next->next; // 5 -> 3
    testList(head2, false);
    
    // Список из одного узла
    Node* headSingle = new Node;
    headSingle->data = 1;
    headSingle->next = nullptr;
    testList(headSingle, true);
    
    // Освобождение памяти
    deleteList(head1);
    deleteList(nodeCyclic1);
    deleteList(nodeJump1);
    deleteList(head2);
    deleteList(headSingle);
    
    return 0;
}

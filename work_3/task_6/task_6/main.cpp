#include <iostream>

using namespace std;

struct Node {
    int data;        // Значение элемента
    int priority;    // Приоритет (меньшее значение — выше приоритет)
    Node* next;      // Указатель на следующий элемент
};

class PriorityQueue {
private:
    Node* head;  // Указатель на голову списка

public:
    PriorityQueue() : head(nullptr) {}

    // Вставка элемента с учетом приоритета
    void enqueue(int data, int priority) {
        Node* newNode = new Node{data, priority, nullptr};

        // Если список пуст или новый узел имеет более высокий приоритет
        if (!head || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            // Поиск позиции вставки
            Node* current = head;
            while (current->next && current->next->priority <= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Удаление элемента с наивысшим приоритетом (т.е. головы)
    void dequeue() {
        if (!head) {
            cout << "Очередь пуста\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "Удален элемент: " << temp->data << " (приоритет " << temp->priority << ")\n";
        delete temp;
    }

    // Получить элемент с наивысшим приоритетом
    int peek() const {
        if (!head) {
            throw runtime_error("Очередь пуста");
        }
        return head->data;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return head == nullptr;
    }

    // Вывод всей очереди
    void display() const {
        Node* current = head;
        cout << "Очередь: ";
        while (current) {
            cout << "[" << current->data << " (p=" << current->priority << ")] ";
            current = current->next;
        }
        cout << endl;
    }

    // Освобождение памяти
    ~PriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Пример использования
int main() {
    PriorityQueue pq;

    pq.enqueue(4, 2);
    pq.enqueue(5, 1);
    pq.enqueue(6, 3);
    pq.enqueue(7, 0);

    pq.display();

    cout << "Наивысший приоритет: " << pq.peek() << endl;

    pq.dequeue();
    pq.display();

    return 0;
}


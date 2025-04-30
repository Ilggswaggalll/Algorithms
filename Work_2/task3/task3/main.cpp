#include <iostream>
using namespace std;

// Перечисление цветов узлов
enum Color { RED, BLACK };

// Структура узла дерева
struct Node {
    int key;
    Node* left;
    Node* right;
    Color color;  // Цвет узла

    Node(int k) {
        key = k;
        left = right = nullptr;
        color = RED;  // При вставке новый узел всегда красный
    }
};

// Вставка узла в двоичное дерево поиска (BST)
Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    
    if (key < root->key)
        root->left = insertBST(root->left, key);
    else if (key > root->key)
        root->right = insertBST(root->right, key);
    
    return root;
}

// Функция для проверки, является ли дерево красно-черным

// 1. Проверка свойства 2: Корень всегда черный
bool isRootBlack(Node* root) {
    return root->color == BLACK;
}

// 2. Проверка свойства 4: Красный узел не может иметь красных потомков
bool hasNoRedRedViolation(Node* node) {
    if (!node) return true;
    
    if (node->color == RED) {
        if ((node->left && node->left->color == RED) ||
            (node->right && node->right->color == RED))
            return false;
    }

    return hasNoRedRedViolation(node->left) && hasNoRedRedViolation(node->right);
}

// 3. Проверка свойства 5: Все пути должны содержать одинаковое количество черных узлов
int countBlackNodes(Node* node) {
    if (!node) return 1; // NIL узлы считаются черными
    
    int leftBlackHeight = countBlackNodes(node->left);
    int rightBlackHeight = countBlackNodes(node->right);
    
    if (leftBlackHeight != rightBlackHeight)
        return -1; // Ошибка, пути не равны
    
    return leftBlackHeight + (node->color == BLACK ? 1 : 0);
}

// Проверка всех свойств красно-черного дерева
bool isRBTree(Node* root) {
    if (!isRootBlack(root)) {
        cout << "Ошибка: Корень не черный!" << endl;
        return false;
    }
    if (!hasNoRedRedViolation(root)) {
        cout << "Ошибка: Найдены два красных узла подряд!" << endl;
        return false;
    }
    if (countBlackNodes(root) == -1) {
        cout << "Ошибка: Черная высота путей не одинакова!" << endl;
        return false;
    }

    return true;
}

// Функция для печати дерева (in-order обход)
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << "(" << (root->color == RED ? "R" : "B") << ") ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int values[] = {10, 20, 30, 15, 25, 5, 1};

    // Строим обычное бинарное дерево поиска
    for (int val : values)
        root = insertBST(root, val);

    // Выводим дерево
    cout << "Дерево (in-order): ";
    inOrder(root);
    cout << endl;

    // Проверяем, является ли оно красно-черным
    if (isRBTree(root))
        cout << "Дерево является красно-черным!" << endl;
    else
        cout << "Дерево НЕ является красно-черным!" << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Структура узла дерева
struct Node {
    int key;        // Значение узла
    Node* left;     // Левый потомок
    Node* right;    // Правый потомок
    int balance;    // Баланс узла
};

// Функция создания нового узла
Node* createNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->balance = 0;
    return node;
}

// Вставка узла в двоичное дерево поиска
Node* insert(Node* root, int key) {
    if (!root) return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Функция вычисления высоты поддерева
int height(Node* node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

// Функция вычисления баланса для каждого узла
void calculateBalance(Node* root) {
    if (root) {
        root->balance = height(root->left) - height(root->right);
        calculateBalance(root->left);
        calculateBalance(root->right);
    }
}

// Функция симметричного (in-order) обхода дерева
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << "(" << root->balance << ") ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int values[] = {30, 20, 10, 25, 40, 50};
    for (int val : values) {
        root = insert(root, val);
    }
    
    // Вычисление баланса для каждого узла
    calculateBalance(root);
    
    // Вывод элементов в порядке in-order с балансом
    cout << "Отсортированные элементы с балансом: ";
    inOrder(root);
    cout << endl;
    
    return 0;
}

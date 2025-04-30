#include <iostream>
using namespace std;

// Структура узла АВЛ-дерева
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Функция для создания нового узла
Node* createNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

// Функция для получения высоты узла
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Функция для вычисления баланса узла
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Правый поворот (LL)
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    
    return x;
}

// Левый поворот (RR)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    
    return y;
}

// Вставка узла с балансировкой
Node* insert(Node* root, int key) {
    if (!root) return createNode(key);
    
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    int balance = getBalance(root);
    
    // LL - Левый поворот
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);
    
    // RR - Правый поворот
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);
    
    // LR - Лево-правый поворот
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    
    // RL - Право-левый поворот
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    
    return root;
}

// Функция симметричного (in-order) обхода дерева
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << "(" << getBalance(root) << ") ";
        inOrder(root->right);
    }
}

// Функция для поиска минимального узла в дереве
Node* getMinValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

// Удаление узла с балансировкой
Node* remove(Node* root, int key) {
    if (!root) return root;

    // Обычное удаление узла
    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else {
        // Узел с одним или без потомков
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            // Узел с двумя потомками
            Node* temp = getMinValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    // Если дерево пустое
    if (!root) return root;

    // Обновляем высоту
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Балансировка
    int balance = getBalance(root);

    // LL - Левый поворот
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // LR - Лево-правый поворот
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RR - Правый поворот
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // RL - Право-левый поворот
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

int main() {
    Node* root = nullptr;
    int values[] = {30, 20, 10, 25, 40, 50};
    for (int val : values) {
        root = insert(root, val);
        inOrder(root);
        cout << endl;
    }
    
    // Вывод элементов в порядке in-order с балансом
    cout << "Отсортированные элементы с балансом: ";
    inOrder(root);
    cout << endl;
    
    return 0;
}

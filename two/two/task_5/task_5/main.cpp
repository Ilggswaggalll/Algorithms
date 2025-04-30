#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Структура узла двоичного дерева поиска
struct Node {
    int data;
    Node* left;
    Node* right;

    // Конструктор для инициализации узла
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Класс для двоичного дерева поиска
class BinarySearchTree {
private:
    Node* root;

    // Вспомогательная рекурсивная функция для добавления узла в дерево
    Node* addNode(Node* root, int value) {
        if (!root) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = addNode(root->left, value);
        } else {
            root->right = addNode(root->right, value);
        }
        return root;
    }

    // Вспомогательная рекурсивная функция для симметричного обхода дерева
    void inorderTraversal(Node* root) {
        if (root) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    // Вспомогательная рекурсивная функция для прямого обхода дерева
    void preorderTraversal(Node* root) {
        if (root) {
            cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    // Вспомогательная рекурсивная функция для обратного обхода дерева
    void postorderTraversal(Node* root) {
        if (root) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << " ";
        }
    }

    // Вспомогательная рекурсивная функция для вычисления глубины дерева
    int calculateHeight(Node* root) {
        if (!root) return 0;
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    // Вспомогательная рекурсивная функция для поиска элемента
    Node* search(Node* root, int value) {
        if (!root || root->data == value) {
            return root;
        }
        if (value < root->data) {
            return search(root->left, value);
        }
        return search(root->right, value);
    }

    // Вспомогательная рекурсивная функция для удаления узла
    Node* deleteNode(Node* root, int value) {
        if (!root) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            // Узел с одним или двумя дочерними узлами
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Узел с двумя дочерними узлами: Получаем минимальный узел в правом поддереве
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Вспомогательная функция для нахождения минимального узла
    Node* findMin(Node* root) {
        Node* current = root;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

public:
    // Конструктор для инициализации дерева
    BinarySearchTree() : root(nullptr) {}

    // Функция для добавления узла в дерево
    void addNode(int value) {
        root = addNode(root, value);
    }

    // Функция для симметричного обхода дерева
    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }

    // Функция для прямого обхода дерева
    void preorderTraversal() {
        preorderTraversal(root);
        cout << endl;
    }

    // Функция для обратного обхода дерева
    void postorderTraversal() {
        postorderTraversal(root);
        cout << endl;
    }

    // Функция для вычисления глубины дерева
    int calculateHeight() {
        return calculateHeight(root);
    }

    // Функция для поиска элемента
    bool search(int value) {
        return search(root, value) != nullptr;
    }

    // Функция для удаления узла
    void deleteNode(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    srand(time(0));

    BinarySearchTree tree;
    int n, value;

    cout << "Введите количество элементов дерева: ";
    cin >> n;

    // Заполнение дерева случайными числами
    for (int i = 0; i < n; ++i) {
        value = rand() % 100 + 1;  // случайное число от 1 до 100
        tree.addNode(value);
    }

    cout << "Симметричный обход (inorder): ";
    tree.inorderTraversal();

    cout << "Прямой обход (preorder): ";
    tree.preorderTraversal();

    cout << "Обратный обход (postorder): ";
    tree.postorderTraversal();

    cout << "Глубина дерева: " << tree.calculateHeight() << endl;

    // Поиск элемента
    cout << "Введите значение для поиска: ";
    cin >> value;
    if (tree.search(value)) {
        cout << "Элемент найден!" << endl;
    } else {
        cout << "Элемент не найден!" << endl;
    }

    // Удаление элемента
    cout << "Введите значение для удаления: ";
    cin >> value;
    tree.deleteNode(value);
    cout << "После удаления: Симметричный обход (inorder): ";
    tree.inorderTraversal();

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Структура для представления узла дерева отрезков
struct SegmentTreeNode {
    int left, right; // Интервал [left, right]
    int count;       // Количество отрезков, содержащих точку X (для узла)
    SegmentTreeNode *leftChild, *rightChild;

    SegmentTreeNode(int l, int r) : left(l), right(r), count(0), leftChild(nullptr), rightChild(nullptr) {}
};

// Класс для дерева отрезков
class SegmentTree {
private:
    SegmentTreeNode* root;

    // Рекурсивная функция для построения дерева отрезков
    SegmentTreeNode* buildTree(int l, int r) {
        if (l > r) return nullptr;
        SegmentTreeNode* node = new SegmentTreeNode(l, r);
        if (l == r) {
            node->count = 0; // Изначально на каждом листе нет интервалов
        } else {
            int mid = (l + r) / 2;
            node->leftChild = buildTree(l, mid);
            node->rightChild = buildTree(mid + 1, r);
        }
        return node;
    }

    // Рекурсивная функция для добавления интервала в дерево
    void addInterval(SegmentTreeNode* node, int l, int r) {
        if (!node || l > node->right || r < node->left) return;
        
        // Если интервал целиком внутри текущего узла, увеличиваем его count
        if (l <= node->left && r >= node->right) {
            node->count++;
            return;
        }

        // Иначе добавляем интервал в оба поддерева
        int mid = (node->left + node->right) / 2;
        addInterval(node->leftChild, l, r);
        addInterval(node->rightChild, l, r);
    }

    // Рекурсивная функция для симметричного обхода дерева
    void inorderTraversal(SegmentTreeNode* node) {
        if (!node) return;
        inorderTraversal(node->leftChild);
        cout << "[" << node->left << ", " << node->right << "] - count: " << node->count << endl;
        inorderTraversal(node->rightChild);
    }

    // Рекурсивная функция для подсчета интервалов, содержащих точку X
    int countIntervalsContainingX(SegmentTreeNode* node, int x) {
        if (!node || x < node->left || x > node->right) return 0;

        // Если узел полностью покрывает точку X, возвращаем count этого узла
        if (x >= node->left && x <= node->right) {
            return node->count;
        }

        // Иначе ищем в обоих поддеревьях
        return countIntervalsContainingX(node->leftChild, x) + countIntervalsContainingX(node->rightChild, x);
    }

public:
    // Конструктор для инициализации дерева отрезков
    SegmentTree(int l, int r) {
        root = buildTree(l, r);
    }

    // Функция для добавления интервала в дерево
    void addInterval(int l, int r) {
        addInterval(root, l, r);
    }

    // Функция для симметричного обхода дерева
    void inorderTraversal() {
        inorderTraversal(root);
    }

    // Функция для подсчета интервалов, содержащих точку X
    int countIntervalsContainingX(int x) {
        return countIntervalsContainingX(root, x);
    }
};

int main() {
    int l, r;
    cout << "Введите границы интервала дерева: ";
    cin >> l >> r;
    
    SegmentTree tree(l, r);
    
    int n;
    cout << "Введите количество интервалов: ";
    cin >> n;
    
    // Добавление интервалов в дерево
    for (int i = 0; i < n; ++i) {
        int intervalLeft, intervalRight;
        cout << "Введите интервал " << i + 1 << " (левая и правая границы): ";
        cin >> intervalLeft >> intervalRight;
        tree.addInterval(intervalLeft, intervalRight);
    }
    
    // Обход дерева
    cout << "Симметричный обход дерева:" << endl;
    tree.inorderTraversal();
    
    // Запрос на точку X
    int x;
    cout << "Введите точку X: ";
    cin >> x;

    // Подсчет количества интервалов, содержащих точку X
    int result = tree.countIntervalsContainingX(x);
    cout << "Количество интервалов, содержащих точку " << x << ": " << result << endl;

    return 0;
}

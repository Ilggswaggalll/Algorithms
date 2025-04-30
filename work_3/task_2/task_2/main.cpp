#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Вспомогательная функция для восстановления свойств кучи вниз (heapify)
    void heapifyDown(int i) {
        int size = heap.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Вспомогательная функция для восстановления свойств кучи вверх
    void heapifyUp(int i) {
        if (i && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            heapifyUp((i - 1) / 2);
        }
    }

    // Построение кучи из массива
    void buildHeap() {
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
            heapifyDown(i);
    }

public:
    // Конструктор по умолчанию
    MaxHeap() {}

    // Конструктор из массива
    MaxHeap(const vector<int>& arr) {
        heap = arr;
        buildHeap();
    }

    // Получить максимум
    int getMax() const {
        if (heap.empty())
            throw runtime_error("Куча пуста");
        return heap[0];
    }

    // Удаление максимального элемента
    int extractMax() {
        if (heap.empty())
            throw runtime_error("Куча пуста");

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    // Добавление нового элемента
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Отображение текущей кучи
    void printHeap() const {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    vector<int> data = {3, 1, 6, 5, 2, 4};
    MaxHeap heap(data);

    cout << "Куча, построенная из массива: ";
    heap.printHeap();

    cout << "Максимум: " << heap.getMax() << endl;

    cout << "Удаляем максимум: " << heap.extractMax() << endl;
    cout << "Куча после удаления максимума: ";
    heap.printHeap();

    heap.insert(10);
    cout << "Куча после вставки 10: ";
    heap.printHeap();

    return 0;
}

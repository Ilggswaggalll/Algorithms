#include <iostream>
#include <vector>

using namespace std;

// Функция для восстановления кучи
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Основной алгоритм пирамидальной сортировки
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Построение max-heap (кучи)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлечение элементов из кучи по одному
    for (int i = n - 1; i > 0; i--) {
        // Переместить текущий корень в конец
        swap(arr[0], arr[i]);

        // Восстановить кучу для оставшихся элементов
        heapify(arr, i, 0);
    }
}

void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Исходный массив:\n";
    printArray(arr);

    heapSort(arr);

    cout << "Отсортированный массив:\n";
    printArray(arr);

    return 0;
}


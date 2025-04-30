#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int start;
    int end;
};

// Сортировка по времени окончания задачи
bool compareByEndTime(const Task& a, const Task& b) {
    return a.end < b.end;
}

vector<Task> selectMaxTasks(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), compareByEndTime);

    vector<Task> selected;
    int lastEndTime = -1;

    for (const auto& task : tasks) {
        if (task.start >= lastEndTime) {
            selected.push_back(task);
            lastEndTime = task.end;
        }
    }

    return selected;
}

// Пример использования
int main() {
    vector<Task> tasks = {
        {1, 3},
        {2, 5},
        {4, 7},
        {6, 9},
        {8, 10},
        {9, 11}
    };

    vector<Task> selected = selectMaxTasks(tasks);

    cout << "Выбранные непересекающиеся задачи:\n";
    for (const auto& task : selected) {
        cout << "Начало: " << task.start << ", Конец: " << task.end << endl;
    }

    cout << "Максимальное количество задач: " << selected.size() << endl;

    return 0;
}


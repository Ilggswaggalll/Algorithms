#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct MergeStep {
    int a, b, cost;
};

int connectRopes(const vector<int>& ropes, vector<MergeStep>& steps) {
    // min-heap (приоритетная очередь с обратным компаратором)
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());

    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int merged = first + second;
        totalCost += merged;

        steps.push_back({first, second, merged});

        minHeap.push(merged);
    }

    return totalCost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};

    vector<MergeStep> steps;
    int totalCost = connectRopes(ropes, steps);

    cout << "Порядок связывания канатов:\n";
    for (const auto& step : steps) {
        cout << "Связать " << step.a << " + " << step.b << " = " << step.cost << endl;
    }

    cout << "Общие затраты: " << totalCost << endl;

    return 0;
}

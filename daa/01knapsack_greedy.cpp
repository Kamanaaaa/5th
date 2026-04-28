// Lab 12.1: Greedy Approach for 0-1 Knapsack

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int id, weight, value;
    double ratio;
};

int main() {
    int n, capacity;
    cout << "=== Greedy Approach (0-1 Knapsack) ===\n\n";
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "\nEnter weight and value for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
        items[i].id = i + 1;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort by ratio descending
    sort(items.begin(), items.end(), [](const Item &a, const Item &b){
        return a.ratio > b.ratio;
    });

    cout << "\n--- Sorted Items by Ratio ---\n";
    cout << "| ID | Weight | Value | Ratio      | Decision |\n";
    cout << "+----+--------+-------+------------+----------|\n";

    int curr_weight = 0, curr_profit = 0;

    for (auto &item : items) {
        char decision = ' ';
        if (curr_weight + item.weight <= capacity) {
            decision = 'Take';
            curr_weight += item.weight;
            curr_profit += item.value;
        } else {
            decision = 'Skip';
        }
        cout << "|" << setw(4) << item.id << " | "
             << setw(6) << item.weight << " | "
             << setw(5) << item.value << " | "
             << fixed << setprecision(2) << setw(10) << item.ratio << " | "
             << decision << "         |\n";
    }

    cout << "\nMaximum Profit (Greedy): " << curr_profit << endl;
    cout << "Note: This may NOT be optimal for 0-1 Knapsack!\n";

    return 0;
}
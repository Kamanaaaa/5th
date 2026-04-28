// Lab 12.3: Backtracking Approach

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int id, weight, value;
};

int n_items, capacity;
int max_profit = 0;
vector<int> selected_items;

void backtrack(const vector<Item>& items, int index, int curr_w, int curr_v, vector<int>& path) {
    if (index == n_items) {
        if (curr_v > max_profit) {
            max_profit = curr_v;
            selected_items = path;
        }
        return;
    }

    // Try Including Item
    if (curr_w + items[index].weight <= capacity) {
        path.push_back(items[index].id);
        backtrack(items, index + 1, curr_w + items[index].weight, curr_v + items[index].value, path);
        path.pop_back();
    }

    // Try Excluding Item
    path.push_back(items[index].id); // Just for trace
    backtrack(items, index + 1, curr_w, curr_v, path);
}

int main() {
    cout << "=== Backtracking Approach (0-1 Knapsack) ===\n\n";
    int n, cap;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> cap;

    vector<Item> items(n);
    cout << "\nEnter weight and value for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
        items[i].id = i + 1;
    }

    n_items = n;
    capacity = cap;
    vector<int> path;

    cout << "\n--- Searching All Subsets ---\n";
    backtrack(items, 0, 0, 0, path);

    cout << "\nMaximum Profit (Backtracking): " << max_profit << endl;
    cout << "Selected Items: ";
    for (int id : selected_items) cout << id << " ";
    cout << endl;

    return 0;
}
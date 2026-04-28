// Lab 12.2: Dynamic Programming Approach

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, capacity;
    cout << "=== Dynamic Programming Approach (0-1 Knapsack) ===\n\n";
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<int> weight(n), value(n);
    cout << "\nEnter weight and value for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> weight[i] >> value[i];
    }

    // Create DP Table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    cout << "\n--- Filling DP Table ---\n";
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "\nSelected Items (Backtrace):\n";
    int i = n, j = capacity;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            cout << "-> Item " << i << " (Weight=" << weight[i - 1] 
                 << ", Value=" << value[i - 1] << ") Selected\n";
            j -= weight[i - 1];
        }
        i--;
    }

    cout << "\nMaximum Profit (DP): " << dp[n][capacity] << endl;
    cout << "? Optimal Solution Guaranteed\n";

    return 0;
}
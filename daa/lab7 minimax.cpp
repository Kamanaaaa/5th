#include <iostream>
using namespace std;

struct Pair {
    int min;
    int max;
};

int comparisons = 0; // global counter

Pair minMax(int a[], int low, int high) {
    Pair result, left, right;

    // Only one element
    if (low == high) {
        result.min = result.max = a[low];
        return result;
    }

    // Two elements
    if (high == low + 1) {
        comparisons++;
        if (a[low] < a[high]) {
            result.min = a[low];
            result.max = a[high];
        } else {
            result.min = a[high];
            result.max = a[low];
        }
        return result;
    }

    // More than 2 elements: divide
    int mid = (low + high) / 2;
    left = minMax(a, low, mid);
    right = minMax(a, mid + 1, high);

    // Combine results
    comparisons++;
    result.min = (left.min < right.min) ? left.min : right.min;

    comparisons++;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Pair result = minMax(a, 0, n - 1);

    cout << "\nMinimum element = " << result.min << endl;
    cout << "Maximum element = " << result.max << endl;

    cout << "Total comparisons = " << comparisons << endl;

    // Verify 3n/2 - 2
    double expected = 1.5 * n - 2;
    cout << "Expected comparisons (3n/2 - 2) = " << expected << endl;

    return 0;
}

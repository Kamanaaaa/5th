// Lab 7.3 (Short): Quick Sort using Divide & Conquer (Hoare Partition)
#include <iostream>
#include <vector>
using namespace std;

bool TRACE = false;

void print(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

// Hoare partition: returns index p such that [low..p] <= pivot and [p+1..high] >= pivot (not strictly sorted)
int partitionHoare(vector<int>& a, int low, int high) {
    int pivot = a[low];
    int i = low - 1, j = high + 1;

    if (TRACE) cout << "pivot=" << pivot << " range=[" << low << "," << high << "]\n";

    while (true) {
        do { i++; } while (a[i] < pivot);
        do { j--; } while (a[j] > pivot);

        if (i >= j) return j;

        swap(a[i], a[j]);
        if (TRACE) {
            cout << " swap a[" << i << "] and a[" << j << "]: ";
            print(a);
        }
    }
}

void quickSort(vector<int>& a, int low, int high) {
    if (low >= high) return;
    int p = partitionHoare(a, low, high);
    quickSort(a, low, p);
    quickSort(a, p + 1, high);
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Enter TRACE (0/1): ";
    cin >> TRACE;

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    print(a);
    return 0;
}
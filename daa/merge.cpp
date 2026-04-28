#include <iostream>
using namespace std;

// Print array from index l to h
void printArray(int a[], int l, int h) {
    for (int i = l; i <= h; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Merge two subarrays a[l..m] and a[m+1..h]
void merge(int a[], int l, int m, int h) {
    int i = l, j = m + 1, k = 0;
    int temp[h - l + 1];

    while (i <= m && j <= h)
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];

    while (i <= m) temp[k++] = a[i++];
    while (j <= h) temp[k++] = a[j++];

    for (int i = 0; i < k; i++)
        a[l + i] = temp[i];

    cout << "Merged (" << l << "," << h << "): ";
    printArray(a, l, h);
}

// MergeSort function
void mergeSort(int a[], int l, int h) {
    if (l < h) {
        int m = (l + h) / 2;
        cout << "Divide (" << l << "," << m << ") and (" << m + 1 << "," << h << ")" << endl;

        mergeSort(a, l, m);       // Sort left half
        mergeSort(a, m + 1, h);   // Sort right half
        merge(a, l, m, h);        // Merge
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int a[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n--- Merge Sort Trace ---\n";
    mergeSort(a, 0, n - 1);

    cout << "\nFinal Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
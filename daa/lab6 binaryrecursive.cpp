#include <iostream>
using namespace std;

int binarySearchRecursive(int a[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == key)
        return mid;
    else if (a[mid] < key)
        return binarySearchRecursive(a, mid + 1, high, key);
    else
        return binarySearchRecursive(a, low, mid - 1, key);
}
int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> key;

    int pos1 = binarySearchRecursive(a, 0, n - 1, key);

    if (pos1 != -1)
        cout << "Element found at index " << pos1 << endl;
    else
        cout << "Element not found\n";

    return 0;
}

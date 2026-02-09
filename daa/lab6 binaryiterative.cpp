#include <iostream>
using namespace std;

int binary(int a[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
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

    int pos1 = binary(a, n, key);

    if (pos1 != -1)
        cout << "Element found at index " << pos1 << endl;
    else
        cout << "Element not found\n";

    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

//bubble
void bubbleSort(int a[], int n) {

    cout << "\nBUBBLE SORT DRY RUN TABLE\n";
    cout << "----------------------------------------------------------\n";
    cout << left << setw(8) << "Pass"
         << setw(25) << "Main Condition"
         << "Array State\n";
    cout << "----------------------------------------------------------\n";

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        cout << left << setw(8) << i + 1
             << setw(25) << "a[j] > a[j+1]";
        printArray(a, n);
        cout << endl;
    }

}

//selection
void selectionSort(int a[], int n) {

    cout << "\nSELECTION SORT DRY RUN TABLE\n";
    cout << "----------------------------------------------------------\n";
    cout << left << setw(8) << "Pass"
         << setw(25) << "Main Condition"
         << "Array State\n";
    cout << "----------------------------------------------------------\n";

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        cout << left << setw(8) << i + 1
             << setw(25) << "a[j] < a[min]";
        printArray(a, n);
        cout << endl;
    }

}

//insertion
void insertionSort(int a[], int n) {

    cout << "\nINSERTION SORT DRY RUN TABLE\n";
    cout << "----------------------------------------------------------\n";
    cout << left << setw(8) << "Pass"
         << setw(25) << "Main Condition"
         << "Array State\n";
    cout << "----------------------------------------------------------\n";

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0) {
            if (a[j] > key) {
                a[j + 1] = a[j];
                j--;
            } else {
                break;
            }
        }
        a[j + 1] = key;

        cout << left << setw(8) << i
             << setw(25) << "a[j] > key";
        printArray(a, n);
        cout << endl;
    }

}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], b1[n], b2[n], b3[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        b1[i] = b2[i] = b3[i] = arr[i];
    }

    bubbleSort(b1, n);
    selectionSort(b2, n);
    insertionSort(b3, n);

    return 0;
}


#include <iostream>
using namespace std;

// Recursive function
int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    // Iterative Method
    cout << "\nTracing Table (Iterative Method):\n";
    cout << "Step\ta\tb\tFibonacci\n";
    cout << "-------------------------------\n";

    int a = 0, b = 1, c;

    if (n >= 1)
        cout << "1\t" << a << "\t-\t" << a << endl;
    if (n >= 2)
        cout << "2\t" << a << "\t" << b << "\t" << b << endl;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        cout << i << "\t" << a << "\t" << b << "\t" << c << endl;
        a = b;
        b = c;
    }

    // Recursive Method
    cout << "\nTracing Table (Recursive Method):\n";
    cout << "n\tFibonacci(n)\n";
    cout << "-----------------\n";

    for (int i = 0; i < n; i++) {
        cout << i << "\t" << fib(i) << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

long factorial(int n) {
    cout << "factorial(" << n << ") called" << endl;

    if (n == 0 || n == 1) {
        cout << "factorial(" << n << ") returns 1" << endl;
        return 1;
    } else {
        long res = n * factorial(n - 1);
        cout << "factorial(" << n << ") returns " << res << endl;
        return res;
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "\nTracing the recursive calls:\n";
    long result = factorial(n);

    cout << "\nFactorial of " << n << " is " << result << endl;
    return 0;
}
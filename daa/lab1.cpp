#include <iostream>
using namespace std;

int main() {
    int n;
    long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    cout << "\nTracing the computation:\n";
    cout << "i\tfact\n";
    cout << "-----------\n";

    for (int i = 1; i <= n; i++) {
        fact = fact * i;
        cout << i << "\t" << fact << endl;
    }

    cout << "\nFactorial of " << n << " is " << fact << endl;
    return 0;
}
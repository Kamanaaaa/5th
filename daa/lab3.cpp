#include <iostream>
using namespace std;

int main() {
    int a, b, r;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\nTracing Euclid's Algorithm:\n";
    cout << "a\tb\tr\n";
    cout << "-----------------\n";

    while (b != 0) {
        r = a % b;
        cout << a << "\t" << b << "\t" << r << endl;
        a = b;
        b = r;
    }

    cout << "\nGCD is " << a << endl;
    return 0;
}
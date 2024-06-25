#include <cmath>
#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long q = sqrt(n);
    if (q * q < n) {
        cout << q + 1;
    } else {
        cout << q;
    }
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> vec(m);
        long long sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> vec[j];
        }
        for (int j = 0; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                int big = max(vec[k], vec[j]);
                int small = min(vec[k], vec[j]);
                sum += gcd(big, small);
            }
        }
        cout << sum << '\n';
    }
}

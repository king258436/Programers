#include <iostream>
using namespace std;
int dp[20][20];
int main() {
    for (int i = 0; i < 20; i++) {
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int n_cnt = 0;
    int n, m, k;
    cin >> n >> m >> k;
    int n_left = k;
    int m_left;
    while (n_left > m) {
        n_left -= m;
        n_cnt++;
    }
    m_left = n_left - 1;

    if (m_left < 0) {
        n_cnt -= 1;
        m_left = m - 1;
    }
    if (k == 0) {
        cout << dp[n - 1][m - 1];
    } else {
        cout << dp[n_cnt][m_left] * dp[n - n_cnt-1 ][m - m_left-1];
    }
}

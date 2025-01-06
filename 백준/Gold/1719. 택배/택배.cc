#include <iostream>
#define INF 1e9
using namespace std;
int n, m;
int adj[201][201];
int ans[201][201];
int main() {
    cin >> n >> m;
    int a, b, c;
    // memset(adj, INF, sizeof(adj));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                adj[i][j] = 0;
            } else
                adj[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
        ans[a][b] = b;
        ans[b][a] = a;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                    ans[i][j] = ans[i][k];
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == 0)
                cout << "- ";
            else {
                cout << ans[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}
#include <iostream>
#define MAX_V 501
#define INF 1e9
using namespace std;

int adj[MAX_V][MAX_V];
int n, m;

void floyd() {
    for (int i = 1; i <= n; i++) {
        adj[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    floyd();
    int result = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] != INF || adj[j][i] != INF)
                cnt++;
        }
        if (cnt == n) {
            result++;
        }
    }
    cout << result;
}
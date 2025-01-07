#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;
int adj[101][101];
int n, m;

int main() {
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    vector<pair<int, pair<int, int>>> vec;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int hap = 0;
            for (int k = 1; k <= n; k++) {
                hap += min(adj[k][i], adj[k][j]);
            }
            vec.push_back({hap, {i, j}});
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec[0].second.first << ' ' << vec[0].second.second << ' ' << vec[0].first * 2;
}

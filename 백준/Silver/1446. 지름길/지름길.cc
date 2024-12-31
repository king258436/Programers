#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;
int N, D;
vector<pair<int, int>> adj[10001];
vector<int> dist(10001, INF);
void dijkstra() {
    dist[0] = 0;
    for (int i = 1; i <= D; i++) {

        dist[i] = dist[i - 1] + 1;

        for (int j = 0; j < adj[i].size(); j++) {
            dist[i] = min(dist[i], dist[adj[i][j].first] + adj[i][j].second);
        }
    }
}
int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[b].push_back({a, d});
    }
    dijkstra();
    cout << dist[D];
}
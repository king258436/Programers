#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;
int n, m, k, x;
vector<int> dist(300001, INF);
vector<int> vec[300001];
void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    dist[x] = 0;
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for (int i = 0; i < vec[here].size(); i++) {
            int there = vec[here][i];
            int nextDist = cost + 1;
            if (nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push({-(nextDist), there});
            }
        }
    }
}
int main() {
    cin >> n >> m >> k >> x;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
    }
    dijkstra();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            cnt++;
            cout << i << "\n";
        }
    }
    if (cnt == 0) {
        cout << -1;
    }
}
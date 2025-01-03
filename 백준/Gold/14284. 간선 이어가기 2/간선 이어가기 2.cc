#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;
vector<pair<int, int>> vec[5001];
vector<int> dist(5001, INF);
int n, m, s, t;

void djikstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) {
            continue;
        }
        for (int i = 0; i < vec[here].size(); i++) {
            int there = vec[here][i].first;
            int nextDist = cost + vec[here][i].second;
            if (nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    cin >> s >> t;
    djikstra();
    cout << dist[t];
}
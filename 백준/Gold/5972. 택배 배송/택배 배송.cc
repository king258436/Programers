#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int n, m;

vector<pair<int, int>> adj[50001];
vector<int> dist(50001, INF);
void djkstra() {
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

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
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    djkstra();
    cout << dist[n];
}
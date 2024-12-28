#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int n, m;

int bfs(int start) {
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> que; // {node, distance}
    que.push({start, 0});
    visited[start] = true;

    int score = 0;

    while (!que.empty()) {
        int cur = que.front().first;
        int dist = que.front().second;
        que.pop();

        score += dist;

        for (int neighbor : graph[cur]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                que.push({neighbor, dist + 1});
            }
        }
    }
    return score;
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int result_value = 1e9;
    int result;

    for (int i = 1; i <= n; i++) {
        int value = bfs(i);
        if (value < result_value) {
            result_value = value;
            result = i;
        }
    }

    cout << result << endl;
    return 0;
}

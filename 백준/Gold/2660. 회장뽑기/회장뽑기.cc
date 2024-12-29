#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct info {
    int num;
    int dist;
} Info;
int n;
vector<vector<int>> vec;

Info bfs(int start) {
    queue<Info> que;
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    int meet_cnt = 1;
    // // 디버깅
    // cout << "start " << start << endl;

    que.push({start, 0});
    while (!que.empty()) {
        Info cur = que.front();
        que.pop();

        for (int next : vec[cur.num]) {
            if (visited[next])
                continue;
            que.push({next, cur.dist + 1});
            // // 디버깅
            // cout << "catch " << next << ' ' << cur.dist + 1 << endl;
            visited[next] = true;
            meet_cnt++;
            if (meet_cnt == n) {
                return {next, cur.dist + 1};
            }
        }
    }
}

bool compare(Info a, Info b) {
    if (a.dist == b.dist)
        return a.num < b.num;
    return a.dist < b.dist;
}

int main() {
    cin >> n;
    vec.resize(n + 1);
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    vector<Info> result_arr;

    for (int i = 1; i <= n; i++) {
        Info rt = bfs(i);
        result_arr.push_back({i,rt.dist});
        // //디버깅
        // cout << "result_arr->push(num, dist) : " << i << ' ' << rt.dist << endl;
    }

    sort(result_arr.begin(), result_arr.end(), compare);
    vector<Info> result;
    Info first = result_arr[0];
    result.push_back(first);
    for (int i = 1; i < n; i++) {
        if (first.dist == result_arr[i].dist) {
            result.push_back(result_arr[i]);
        }
    }

    // for (Info p : result_arr) { // 디버깅
    //     cout << p.num << ' ' << p.dist << endl;
    // }

    cout << first.dist << ' ' << result.size() << endl; //출력
    for (Info p : result) {
        cout << p.num << ' ';
    }
}
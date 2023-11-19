#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

struct Info {
    int p0;
    int p1;
    int p2;
};
bool visited[201][201];
int n;
string str[3];
int p[3];
int len[3];

bool bfs() {
    queue<Info> que;
    que.push({0, 0, 0});
    bool flag = false;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        if (cur.p2 >= len[2]) {
            flag = true;
            break;
        }
        if (cur.p0 < len[0] && str[0][cur.p0] == str[2][cur.p2] && !visited[cur.p0 + 1][cur.p1]) {
            que.push({cur.p0 + 1, cur.p1, cur.p2 + 1});
            visited[cur.p0 + 1][cur.p1] = true;
        }
        if (cur.p1 < len[1] && str[1][cur.p1] == str[2][cur.p2] && !visited[cur.p0][cur.p1 + 1]) {
            que.push({cur.p0, cur.p1 + 1, cur.p2 + 1});
            visited[cur.p0 + 1][cur.p1] = true;
        }
    }
    if (flag) {
        return true;
    } else {
        return false;
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        cin >> str[0] >> str[1] >> str[2];
        for (int j = 0; j < 3; j++) {
            len[j] = str[j].size();
        }
        bool result_flag = bfs();
        cout << "Data set " << i + 1 << ": ";
        if (result_flag) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
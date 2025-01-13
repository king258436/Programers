#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vec;
bool visited[1002];
int main() {
    int n;
    cin >> n;
    vec.push_back(0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    queue<int> que;
    int result_cnt = 0;
    int result = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        que.push(i);
        visited[i]=true;
        while (!que.empty()) {
            cnt++;
            int cur = que.front();
            que.pop();
            if (!visited[vec[cur]]) {
                que.push(vec[cur]);
                visited[vec[cur]] = true;
            }
        }
        if (result_cnt < cnt) {
            result_cnt = cnt;
            result = i;
        }
    }
    cout << result;
}
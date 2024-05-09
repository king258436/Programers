#include <iostream>
#include <string>
using namespace std;
int dx[] = {0, -1, 0, 1};  // [0]부터 남 서 북 동
int dy[] = {1, 0, -1, 0};
char map[102][102];

typedef struct St {
    int y;
    int x;
} st;

int width_min = 50, width_max = 50, height_min = 50, height_max = 50;

void check(int y, int x) {
    width_max = max(width_max, x);
    width_min = min(width_min, x);
    height_min = min(height_min, y);
    height_max = max(height_max, y);
}

int main() {
    int n;
    string str;
    cin >> n >> str;
    int cur_dir = 0;
    st cur_po;
    cur_po.x = 50;
    cur_po.y = 50;
    bool fFlag = 0;

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            map[i][j] = '#';
        }
    }
    map[cur_po.y][cur_po.x] = '.';
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'R') {
            cur_dir = (cur_dir + 1) % 4;
        } else if (str[i] == 'L') {
            cur_dir = (cur_dir - 1);
            if (cur_dir < 0) cur_dir = 3;
        } else if (str[i] == 'F') {
            cur_po.x += dx[cur_dir];
            cur_po.y += dy[cur_dir];
            map[cur_po.y][cur_po.x] = '.';
            check(cur_po.y, cur_po.x);
        }
    }
    for (int y = height_min; y <= height_max; y++) {
        for (int x = width_min; x <= width_max; x++) {
            cout << map[y][x];
        }
        cout << "\n";
    }
}

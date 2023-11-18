#include<iostream>
#include<string>

#define n 5
using namespace std;
int x_bingo, o_bingo;
int x_cnt, o_cnt;

void cnt_func(string str) {// 개수 체크
    for (int i = 0; i < 9; i++) {
        if (str[i] == 'X') {
            x_cnt++;
        } else if (str[i] == 'O') {
            o_cnt++;
        }
    }
}

void search_bingo(string str) {// 빙고 개수 체크
    for (int i = 0; i < 9; i += 3) {// 가로 빙고 체크
        if (str[i] == 'O' && str[i] == str[i + 1] && str[i] == str[i + 2]) {
            o_bingo++;
        } else if (str[i] == 'X' && str[i] == str[i + 1] && str[i] == str[i + 2]) {
            x_bingo++;
        }
    }
    for (int i = 0; i < 3; i++) {// 세로
        if (str[i] == 'O' && str[i] == str[i + 3] && str[i] == str[i + 6]) {
            o_bingo++;
        } else if (str[i] == 'X' && str[i] == str[i + 3] && str[i] == str[i + 6]) {
            x_bingo++;
        }
    }
    if (str[0] == 'O' && str[4] == 'O' && str[8] == 'O') {
        o_bingo++;
    } else if (str[0] == 'X' && str[4] == 'X' && str[8] == 'X') {
        x_bingo++;
    }

    if (str[2] == 'X' && str[4] == 'X' && str[6] == 'X') {
        x_bingo++;
    } else if (str[2] == 'O' && str[4] == 'O' && str[6] == 'O') {
        o_bingo++;
    }
}

bool solve() {
    bool flag = false;
    if (x_cnt > o_cnt) {
        if (x_cnt != o_cnt + 1 || o_bingo != 0) {// inval 조건
            // false;
        } else if (x_bingo == 0 || x_bingo == 2) {// x빙고 0or2일때
            if (x_cnt + o_cnt == 9) {
                flag = true;
            }
        } else if (x_bingo == 1) {// x빙고 1일때
            flag = true;
        }
    } else if (x_cnt == o_cnt) {
        if (o_bingo == 1 && x_bingo == 0) {
            flag = true;
        }
    } else;
    return flag;
}

void print_test() {
    cout << "x 개수: " << x_cnt << " o 개수: " << o_cnt << " x 빙고개수: " << x_bingo << " o 빙고개수: " << o_bingo << ' ';
}

int main() {
    string str;
    while (cin >> str) {
        if (str == "end") break;
        x_bingo = 0, o_bingo = 0, x_cnt = 0, o_cnt = 0;
        cnt_func(str);
        search_bingo(str);
        bool answer_flag = solve();
//        print_test();
        if (answer_flag) {
            cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
    }
    return 0;
}
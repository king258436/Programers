#include <iostream>
#include <string>
using namespace std;
int check[26];
bool isItGroup(string str) {
    int len = str.length();
    for (int j = 0; j < 26; j++) {
        check[j] = -1;
    }
    for (int j = 0; j < len; j++) {
        if (check[str[j] - 'a'] == -1) {
            check[str[j] - 'a'] = j;
        } else {  // 처음 나온 숫자가 아니라면
            if (check[str[j] - 'a'] == j - 1) {
                check[str[j] - 'a'] = j;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    int result=0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(isItGroup(str)){
            result++;
        }
    }
    cout<<result;
}
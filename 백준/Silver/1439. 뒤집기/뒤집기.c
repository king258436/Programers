#include <stdio.h>
#include <string.h>
int main() {
    char str[1000001];
    scanf("%s", str);
    int len = strlen(str);
    int cnt = 0;
    int d_flag = 0;
    for (int i = 1; i < len; i++) {
        if (str[i] != str[i - 1]) {
            if (d_flag == 1) {
                cnt++;
                d_flag--;
            }
            else
                d_flag++;
        }
    }
    if (d_flag == 1)
        cnt++;
    printf("%d", cnt);
}
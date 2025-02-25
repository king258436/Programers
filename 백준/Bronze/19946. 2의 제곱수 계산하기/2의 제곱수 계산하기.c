#include <stdio.h>

int main() {
    unsigned long long a;
    scanf("%llu", &a);
    int res = 64;
    int cnt = 0;
    while (a) {
        if (a % 2) {
            break;
        }
        res--;
        a /= 2;
    }
    printf("%d", res);
}
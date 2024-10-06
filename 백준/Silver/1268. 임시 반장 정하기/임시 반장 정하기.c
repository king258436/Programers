#include <stdio.h>
int main() {
    int n;
    int students[1001][5] = {
        0,
    };
    int record[1001][1001] = {
        0,
    };
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &students[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        int student = i;
        for (int j = 1; j <= n; j++) {
            int target = j;
            for (int k = 0; k < 5; k++) {
                int grade = k;
                if (students[student][grade] == students[target][k])
                    record[student][target] = 1;
            }
        }
    }
    int max_value = 0;
    int max_student = 0;
    for (int i = 1; i <= n; i++) {
        int cur_value = 0;
        for (int j = 1; j <= n; j++) {
            if (record[i][j])
                cur_value++;
        }
        if (max_value < cur_value) {
            max_student = i;
            max_value = cur_value;
        }
    }
    printf("%d", max_student);
}
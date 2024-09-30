#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int main()
{
    int n, m, cnt = 0;
    int left, right, mid;
    scanf("%d %d", &n, &m);

    char **n_list, **m_list;

    n_list = (char **)calloc(n, sizeof(char *));
    m_list = (char **)calloc(m, sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        n_list[i] = (char *)calloc(21, sizeof(char));
    }
    for (int i = 0; i < m; i++)
    {
        m_list[i] = (char *)calloc(21, sizeof(char));
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s", n_list[i]);
    } // 여까지 이상없음

    qsort(n_list, n, sizeof(n_list[0]), compare);

    for (int i = 0; i < m; i++)
    {
        left = 0;
        right = n - 1;

        scanf("%s", m_list[cnt]);

        while (left <= right)
        {
            mid = (left + right) / 2;
            if (strcmp(m_list[cnt], n_list[mid]) == 0)
            {
                cnt++;
                continue;
            }
            else
            {
                if (strcmp(m_list[cnt], n_list[mid]) < 0)
                {
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
        }
    }

    qsort(m_list, cnt, sizeof(m_list[0]), compare);

    printf("%d", cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("\n%s", m_list[i]);
    }
    free(n_list);
    free(m_list);
    return 0;
}
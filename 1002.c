#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//计算高精度加法
char cal(char *, int, char *, int); //输入输出函数，应该没问题
char ch1[1001], ch2[1001];
int count = 1;
int main()
{
    int t;
    scanf("%d", &t);
    int i, x = 0, y = 0;
    char num1[1001];
    char num2[1001];
    while (t >= count)
    {
        scanf("%s %s", ch1, ch2);
        x = strlen(ch1);
        y = strlen(ch2);

        memset(num1, 0, sizeof(num1[0]) * 1001);
        memset(num2, 0, sizeof(num2[0]) * 1001);

        for (i = 0; i < x; i++)
        {
            num1[i] = ch1[i];
        }
        for (i = 0; i < y; i++)
        {
            num2[i] = ch2[i];
        }

        if (x < y)
        {
            cal(num2, y, num1, x);
        }
        else
        {
            cal(num1, x, num2, y);
        }
        if (count++ != t)
        {
            printf("\n\n");
        }
    }
    return 0;
}

char cal(char *big, int m, char *small, int n)
{
    int sum[1002] = {0};
    int i;
    for (i = 1; i <= n; i++)
    {
        if ((sum[i - 1] += ((big[m - i] - '0') + (small[n - i] - '0'))) >= 10)
        {
            sum[i - 1] -= 10;
            sum[i]++;
        }
    }
    for (; i <= m; i++)
    {
        if (m == n)
        {
            break;
        }
        if ((sum[i - 1] += big[m - i] - '0') >= 10)
        {
            sum[i - 1] -= 10;
            sum[i]++;
        }
    }

    for (; i >= 0; i--)
    {
        if (*(sum + i) == 0)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    printf("Case %d:\n%s + %s = ", count, ch1, ch2);
    for (; i >= 0; i--)
    {
        printf("%d", sum[i]);
    }
    return 0;
}

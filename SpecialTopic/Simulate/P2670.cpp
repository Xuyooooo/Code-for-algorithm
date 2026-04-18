#include <stdio.h>
char input[101][101], output[101][101];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    fflush(stdin);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%c", &input[i][j]);
        }
        getchar();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (input[i][j] == '*')
                output[i][j] = '*';
            else
            {
                int num = 0;
                if (input[i - 1][j - 1] == '*')
                    num++;
                if (input[i - 1][j] == '*')
                    num++;
                if (input[i - 1][j + 1] == '*')
                    num++;
                if (input[i][j - 1] == '*')
                    num++;
                if (input[i][j + 1] == '*')
                    num++;
                if (input[i + 1][j - 1] == '*')
                    num++;
                if (input[i + 1][j] == '*')
                    num++;
                if (input[i + 1][j + 1] == '*')
                    num++;
                output[i][j] = '0' + num;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%c", output[i][j]);
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20
#define INF 999999

int m[MAX][MAX];
int s[MAX][MAX];

void printOptimal(int i, int j)
{
    if(i == j)
    {
        printf("M%d", i);
    }
    else
    {
        printf("(");

        printOptimal(i, s[i][j]);
        printOptimal(s[i][j] + 1, j);

        printf(")");
    }
}

int main()
{
    int n;
    int p[MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array:\n");

    for(int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    clock_t start = clock();

    for(int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for(int L = 2; L <= n; L++)
    {
        for(int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;

            m[i][j] = INF;

            for(int k = i; k < j; k++)
            {
                int q;

                q = m[i][k] +
                    m[k + 1][j] +
                    p[i - 1] * p[k] * p[j];

                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    clock_t end = clock();

    printf("\nM Table (Minimum Multiplications):\n");

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i > j)
                printf("0\t");
            else
                printf("%d\t", m[i][j]);
        }

        printf("\n");
    }

    printf("\nS Table (K Values / Parenthesization):\n");

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i >= j)
                printf("0\t");
            else
                printf("%d\t", s[i][j]);
        }

        printf("\n");
    }

    printf("\nMinimum Multiplications = %d\n", m[1][n]);

    printf("\nOptimal Parenthesization:\n");

    printOptimal(1, n);

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nTime Taken = %f sec\n", time_taken);

    return 0;
}
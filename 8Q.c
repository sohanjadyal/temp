#include <stdio.h>
#include <time.h>

int board[8][8];

int safe(int row, int col)
{
    for(int i = 0; i < col; i++)
    {
        if(board[row][i])
            return 0;
    }

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j])
            return 0;
    }

    for(int i = row, j = col; i < 8 && j >= 0; i++, j--)
    {
        if(board[i][j])
            return 0;
    }

    return 1;
}

int solve(int col)
{
    if(col >= 8)
        return 1;

    for(int i = 0; i < 8; i++)
    {
        if(safe(i, col))
        {
            board[i][col] = 1;

            if(solve(col + 1))
                return 1;

            board[i][col] = 0;
        }
    }

    return 0;
}

int main()
{
    clock_t start = clock();

    solve(0);

    clock_t end = clock();

    printf("Solution:\n");

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%d ", board[i][j]);
        }

        printf("\n");
    }

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time: %f sec\n", time_taken);

    return 0;
}
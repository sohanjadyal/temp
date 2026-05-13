#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define N 4
#define MAX 1000


int final[N][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

struct Node
{
    struct Node* parent;

    int mat[N][N];

    int x, y;

    int cost;
    int level;
};

struct Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, struct Node* parent){
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));

    node->parent = parent;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            node->mat[i][j] = mat[i][j];
        }
    }

    int temp = node->mat[x][y];
    node->mat[x][y] = node->mat[newX][newY];
    node->mat[newX][newY] = temp;

    node->cost = INT_MAX;
    node->level = level;

    node->x = newX;
    node->y = newY;

    return node;
}

int calculateCost(int mat[N][N])
{
    int count = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(mat[i][j] &&
               mat[i][j] != final[i][j])
            {
                count++;
            }
        }
    }

    return count;
}

void printMatrix(int mat[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", mat[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void printPath(struct Node* root)
{
    if(root == NULL)
        return;

    printPath(root->parent);

    printMatrix(root->mat);
}

int isSafe(int x, int y)
{
    return (x >= 0 && x < N &&
            y >= 0 && y < N);
}

struct Node* pq[MAX];
int size = 0;

void push(struct Node* node)
{
    pq[size++] = node;
}

struct Node* pop()
{
    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if((pq[i]->cost + pq[i]->level) <
           (pq[minIndex]->cost + pq[minIndex]->level))
        {
            minIndex = i;
        }
    }

    struct Node* temp = pq[minIndex];

    pq[minIndex] = pq[size - 1];

    size--;

    return temp;
}

void solve(int initial[N][N], int x, int y)
{
    struct Node* root =
        newNode(initial, x, y, x, y, 0, NULL);

    root->cost = calculateCost(initial);

    push(root);

    int row[] = {1, 0, -1, 0};
    int col[] = {0, -1, 0, 1};

    while(size > 0)
    {
        struct Node* min = pop();

        if(min->cost == 0)
        {
            printPath(min);
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int newX = min->x + row[i];
            int newY = min->y + col[i];

            if(isSafe(newX, newY))
            {
                struct Node* child =
                    newNode(min->mat,
                            min->x,
                            min->y,
                            newX,
                            newY,
                            min->level + 1,
                            min);

                child->cost =
                    calculateCost(child->mat);

                push(child);
            }
        }
    }
}

int main()
{
    int initial[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 12, 11},
        {0, 14, 15, 13}
    };

    int x = 3;
    int y = 0;

    clock_t start = clock();

    solve(initial, x, y);

    clock_t end = clock();

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time: %f sec\n", time_taken);

    return 0;
}
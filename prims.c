#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX 100

struct Node
{
    int vertex, weight;
};

struct Node heap[MAX];
int size = 0;

void insert(int vertex, int weight)
{
    int i = ++size;

    while(i > 1 && heap[i/2].weight > weight)
    {
        heap[i] = heap[i/2];
        i /= 2;
    }

    heap[i].vertex = vertex;
    heap[i].weight = weight;
}

struct Node deleteMin()
{
    struct Node min = heap[1];
    struct Node last = heap[size--];

    int i = 1, child;

    while(i * 2 <= size)
    {
        child = i * 2;

        if(child + 1 <= size &&
           heap[child + 1].weight < heap[child].weight)
            child++;

        if(last.weight <= heap[child].weight)
            break;

        heap[i] = heap[child];
        i = child;
    }

    heap[i] = last;

    return min;
}

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int graph[n][n];

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }

    int visited[n];

    for(int i=0;i<n;i++)
        visited[i]=0;

    clock_t start = clock();

    visited[0]=1;

    for(int i=0;i<n;i++)
    {
        if(graph[0][i] != 0)
            insert(i, graph[0][i]);
    }

    int minCost = 0;
    int edges = 0;

    printf("Edges in MST:\n");

    while(edges < n-1 && size > 0)
    {
        struct Node temp = deleteMin();

        int v = temp.vertex;
        int w = temp.weight;

        if(visited[v])
            continue;

        visited[v]=1;

        minCost += w;

        printf("Vertex %d Weight %d\n",v,w);

        edges++;

        for(int i=0;i<n;i++)
        {
            if(graph[v][i] != 0 && !visited[i])
                insert(i, graph[v][i]);
        }
    }

    clock_t end = clock();

    printf("Minimum Cost = %d\n",minCost);

    double time_taken =
        (double)(end-start)/CLOCKS_PER_SEC;

    printf("Time: %f sec",time_taken);

    return 0;
}
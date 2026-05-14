#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int x)
{
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unionSet(int x, int y)
{
    parent[find(x)] = find(y);
}

int compare(const void *a, const void *b)
{
    return ((struct Edge*)a)->w -
           ((struct Edge*)b)->w;
}

int main()
{
    int n, e;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d",&n,&e);

    struct Edge edges[e];

    printf("Enter source destination weight:\n");

    for(int i=0;i<e;i++)
    {
        scanf("%d%d%d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    for(int i=0;i<n;i++)
        parent[i]=i;

    clock_t start = clock();

    qsort(edges, e, sizeof(struct Edge), compare);

    int minCost = 0;

    printf("Edges in MST:\n");

    for(int i=0;i<e;i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(find(u) != find(v))
        {
            printf("%d - %d : %d\n",u,v,w);

            minCost += w;

            unionSet(u,v);
        }
    }

    clock_t end = clock();

    printf("Minimum Cost = %d\n",minCost);

    double time_taken =
        (double)(end-start)/CLOCKS_PER_SEC;

    printf("Time: %f sec",time_taken);

    return 0;
}
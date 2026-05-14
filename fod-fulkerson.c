#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX 100

int visited[MAX];

int dfs(int rGraph[MAX][MAX], int V,
        int u, int t, int flow)
{
    if(u == t)
        return flow;

    visited[u] = 1;

    for(int v=0; v<V; v++)
    {
        if(!visited[v] && rGraph[u][v] > 0)
        {
            int curr_flow;

            if(flow < rGraph[u][v])
                curr_flow = flow;
            else
                curr_flow = rGraph[u][v];

            int temp =
                dfs(rGraph, V, v, t, curr_flow);

            if(temp > 0)
            {
                rGraph[u][v] -= temp;
                rGraph[v][u] += temp;

                return temp;
            }
        }
    }

    return 0;
}

int fordFulkerson(int graph[MAX][MAX],
                  int V, int s, int t)
{
    int rGraph[MAX][MAX];

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            rGraph[i][j] = graph[i][j];
    }

    int maxFlow = 0;

    while(1)
    {
        for(int i=0;i<V;i++)
            visited[i] = 0;

        int flow =
            dfs(rGraph, V, s, t, INT_MAX);

        if(flow == 0)
            break;

        maxFlow += flow;
    }

    return maxFlow;
}

int main()
{
    int V;

    printf("Enter number of vertices: ");
    scanf("%d",&V);

    int graph[MAX][MAX];

    printf("Enter capacity matrix:\n");

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    }

    int source, sink;

    printf("Enter source and sink: ");
    scanf("%d%d",&source,&sink);

    clock_t start = clock();

    int maxFlow =
        fordFulkerson(graph, V, source, sink);

    clock_t end = clock();

    printf("Maximum Flow = %d\n",maxFlow);

    double time_taken =
        (double)(end-start)/CLOCKS_PER_SEC;

    printf("Time: %f sec",time_taken);

    return 0;
}
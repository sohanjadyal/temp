
#include <stdio.h>

#define MAX 100
#define INF 9999

struct Edge {
    int u, v, w;
};

int main() {
    int V, E, i, j, src;
    struct Edge edge[MAX];
    int dist[MAX];

    printf("Enter vertices and edges: ");
    scanf("%d%d", &V, &E);

    printf("Enter edges (u v w):\n");

    for(i = 0; i < E; i++)
        scanf("%d%d%d",
              &edge[i].u,
              &edge[i].v,
              &edge[i].w);

    printf("Enter source: ");
    scanf("%d", &src);

    for(i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(i = 1; i <= V - 1; i++) {
        for(j = 0; j < E; j++) {
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;

            if(dist[u] != INF &&
               dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(j = 0; j < E; j++) {

    int u = edge[j].u;
    int v = edge[j].v;
    int w = edge[j].w;

    if(dist[u] != INF &&
       dist[u] + w < dist[v]) {

        printf("\nNegative Weight Cycle Detected\n");
        return 0;
    }
}

    printf("\nDistances:\n");

    for(i = 0; i < V; i++)
        printf("%d -> %d = %d\n", src, i, dist[i]);

    return 0;
}
#include <stdio.h>

#define INF 9999

int main() {
    int n, cost[10][10], dist[10], visited[10];
    int i, j, count, mindist, nextnode, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source node: ");
    scanf("%d", &src);

    for(i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;
    count = 1;

    while(count < n - 1) {
        mindist = INF;

        for(i = 0; i < n; i++) {
            if(dist[i] < mindist && !visited[i]) {
                mindist = dist[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(i = 0; i < n; i++) {
            if(!visited[i] &&
               mindist + cost[nextnode][i] < dist[i]) {
                dist[i] = mindist + cost[nextnode][i];
            }
        }

        count++;
    }

    printf("\nShortest distances:\n");

    for(i = 0; i < n; i++)
        printf("%d -> %d = %d\n", src, i, dist[i]);

    return 0;
}
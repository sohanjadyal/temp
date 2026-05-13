#include <stdio.h>

int main() {

    int n, e;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d",&n,&e);

    int u[e], v[e];
    int visited[n];

    for(int i=0;i<n;i++)
        visited[i] = 0;

    printf("Enter edges:\n");

    for(int i=0;i<e;i++) {
        scanf("%d%d",&u[i],&v[i]);
    }

    printf("\nVertex Cover:\n");

    for(int i=0;i<e;i++) {

        if(!visited[u[i]] && !visited[v[i]]) {

            visited[u[i]] = 1;
            visited[v[i]] = 1;

            printf("%d %d ",u[i],v[i]);
        }
    }

    return 0;
}
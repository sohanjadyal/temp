#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x, y;
};

int findSide(struct Point p1, struct Point p2, struct Point p) {
    int val = (p.y - p1.y) * (p2.x - p1.x) -
              (p2.y - p1.y) * (p.x - p1.x);

    if(val > 0)
        return 1;

    if(val < 0)
        return -1;

    return 0;
}

int lineDist(struct Point p1, struct Point p2, struct Point p) {
    return abs((p.y - p1.y) * (p2.x - p1.x) -
               (p2.y - p1.y) * (p.x - p1.x));
}

void quickHull(struct Point points[], int n,
               struct Point p1, struct Point p2, int side) {

    int ind = -1;
    int max_dist = 0;

    for(int i=0;i<n;i++) {

        int temp = lineDist(p1,p2,points[i]);

        if(findSide(p1,p2,points[i]) == side &&
           temp > max_dist) {

            ind = i;
            max_dist = temp;
        }
    }

    if(ind == -1) {
        printf("(%d,%d) ", p1.x,p1.y);
        printf("(%d,%d)\n", p2.x,p2.y);
        return;
    }

    quickHull(points,n,points[ind],p1,
              -findSide(points[ind],p1,p2));

    quickHull(points,n,points[ind],p2,
              -findSide(points[ind],p2,p1));
}

int main() {

    int n;

    printf("Enter number of points: ");
    scanf("%d",&n);

    struct Point points[n];

    printf("Enter points:\n");

    for(int i=0;i<n;i++)
        scanf("%d%d",&points[i].x,&points[i].y);

    int min_x = 0, max_x = 0;

    for(int i=1;i<n;i++) {

        if(points[i].x < points[min_x].x)
            min_x = i;

        if(points[i].x > points[max_x].x)
            max_x = i;
    }

    printf("\nConvex Hull Points:\n");

    quickHull(points,n,
              points[min_x],
              points[max_x],1);

    quickHull(points,n,
              points[min_x],
              points[max_x],-1);

    return 0;
}
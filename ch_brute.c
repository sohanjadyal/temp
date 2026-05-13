#include <stdio.h>

struct Point {
    int x, y;
};

int main() {
    struct Point p[100];
    int n, i, j, k;

    printf("Enter number of points: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d %d", &p[i].x, &p[i].y);

    printf("Convex Hull Points:\n");

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {

            int pos = 0, neg = 0;

            for(k = 0; k < n; k++) {
                int val = (p[j].y - p[i].y) * (p[k].x - p[j].x) -
                          (p[j].x - p[i].x) * (p[k].y - p[j].y);

                if(val > 0)
                    pos++;
                else if(val < 0)
                    neg++;
            }

            if(pos == 0 || neg == 0)
                printf("(%d,%d) (%d,%d)\n",
                        p[i].x, p[i].y,
                        p[j].x, p[j].y);
        }
    }

    return 0;
}
#include <stdio.h>
#include <time.h>

int w[20], x[20], n, target;

void subset(int sum, int k) {
    if(sum == target) {
        printf("{ ");
        for(int i=0;i<k;i++) {
            if(x[i])
                printf("%d ", w[i]);
        }
        printf("}\n");
        return;
    }

    if(k == n || sum > target)
        return;

    x[k] = 1;
    subset(sum + w[k], k + 1);

    x[k] = 0;
    subset(sum, k + 1);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);

    printf("Enter target sum: ");
    scanf("%d",&target);

    clock_t start = clock();
    printf("Subsets are:\n");

    subset(0,0);
    
    clock_t end = clock();

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nTime Taken = %f sec\n", time_taken);

    return 0;
}
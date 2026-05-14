#include <stdio.h>
#include <time.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}

int main()
{
    int n,W;

    printf("Enter number of items: ");
    scanf("%d",&n);

    int wt[n], val[n];

    printf("Enter weights:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&wt[i]);

    printf("Enter values:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&val[i]);

    printf("Enter capacity: ");
    scanf("%d",&W);

    int dp[n+1][W+1];

    clock_t start = clock();

    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0 || w==0)
                dp[i][w]=0;
            else if(wt[i-1]<=w)
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            else
                dp[i][w]=dp[i-1][w];
        }
    }

    clock_t end = clock();

    printf("Maximum Profit = %d",dp[n][W]);

    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime: %f sec",time_taken);

    return 0;
}
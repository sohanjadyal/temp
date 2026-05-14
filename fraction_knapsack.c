#include <stdio.h>
#include<time.h>

struct Item
{
    int value, weight;
};

int main()
{
    int n,W;

    printf("Enter number of items: ");
    scanf("%d",&n);

    struct Item item[n];

    printf("Enter value and weight:\n");
    for(int i=0;i<n;i++)
        scanf("%d%d",&item[i].value,&item[i].weight);

    printf("Enter capacity: ");
    scanf("%d",&W);

    clock_t start = clock();

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            float r1=(float)item[i].value/item[i].weight;
            float r2=(float)item[j].value/item[j].weight;

            if(r2>r1)
            {
                struct Item temp=item[i];
                item[i]=item[j];
                item[j]=temp;
            }
        }
    }

    float profit=0;

    for(int i=0;i<n;i++)
    {
        if(item[i].weight<=W)
        {
            profit+=item[i].value;
            W-=item[i].weight;
        }
        else
        {
            profit += item[i].value * ((float)W/item[i].weight);
            break;
        }
    }

    clock_t end = clock();

    printf("Maximum Profit = %f",profit);

    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime: %f sec",time_taken);

    return 0;
}
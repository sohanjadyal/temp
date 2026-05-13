#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter Size: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    clock_t start = clock();

    quickSort(a, 0, n - 1);

    clock_t end = clock();

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime: %f sec", time_taken);

    return 0;
}
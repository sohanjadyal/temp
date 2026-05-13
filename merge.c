#include <stdio.h>
#include <time.h>

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = a[l + i];

    for(int i = 0; i < n2; i++)
        R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while(i < n1)
        a[k++] = L[i++];

    while(j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter Elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    clock_t start = clock();

    mergeSort(a, 0, n - 1);

    clock_t end = clock();

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTime taken: %f sec", time_taken);

    return 0;
}
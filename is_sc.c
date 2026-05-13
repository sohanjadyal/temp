#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++) {
        min = i;

        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void printArray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
    int n, i;
    int arr1[100], arr2[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }

    clock_t start, end;

    start = clock();
    insertionSort(arr1, n);
    end = clock();

    printf("\nInsertion Sort:\n");
    printArray(arr1, n);
    printf("\nTime = %lf", (double)(end - start)/CLOCKS_PER_SEC);

    start = clock();
    selectionSort(arr2, n);
    end = clock();

    printf("\n\nSelection Sort:\n");
    printArray(arr2, n);
    printf("\nTime = %lf", (double)(end - start)/CLOCKS_PER_SEC);

    return 0;
}
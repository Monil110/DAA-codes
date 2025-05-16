#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int s;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int uniqueness(int arr[]) {
    for (int i = 0; i < s - 1; i++) {
        if (arr[i] == arr[i + 1])
            return 1;
    }
    return 0;
}

int main() {
    struct timeval start, end;
    printf("Enter size of array:");
    scanf("%d", &s);
    int arr[s];
    printf("Enter elements:\n");
    for (int i = 0; i < s; i++) {
        scanf("%d", &arr[i]);
    }

    gettimeofday(&start, NULL);
    quickSort(arr, 0, s - 1);
    gettimeofday(&end, NULL);

    printf("Sorted array: \n");
    for (int i = 0; i < s; i++)
        printf("%d ", arr[i]);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long total_microseconds = seconds * 1000000 + microseconds;

    printf("\nTime: %ld microseconds", total_microseconds);

    int a = uniqueness(arr);
    if (a == 1)
        printf("\nNot unique\n");
    else
        printf("\nUnique\n");

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int larr[n1], rarr[n2];
    for (int i = 0; i < n1; i++) larr[i] = arr[i + left];
    for (int j = 0; j < n2; j++) rarr[j] = arr[j + mid + 1];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (larr[i] <= rarr[j]) arr[k++] = larr[i++];
        else arr[k++] = rarr[j++];
    }
    while (i < n1) arr[k++] = larr[i++];
    while (j < n2) arr[k++] = rarr[j++];
}

void ms(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        ms(arr, left, mid);
        ms(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void randomm(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }
}

int main() {
    struct timeval start, end;
    int sizes[10] = {1000, 2000, 5000, 7000, 10000, 12000, 15000, 16000, 18000, 20000};
    for (int i = 0; i < 10; i++) {
        int n = sizes[i];
        int arr[n];
        randomm(arr, n);
        
        gettimeofday(&start, NULL);
        ms(arr, 0, n - 1);
        gettimeofday(&end, NULL);
        
        long sec = end.tv_sec - start.tv_sec;
        long micro = end.tv_usec - start.tv_usec;
        double elap = sec + micro / 1000000.0;
        
        printf("Size: %d, Time taken: %f seconds\n", n, elap);
    }
    
    return 0;
}
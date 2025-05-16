#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

#define N 10
int board[N][N];

bool issafe(int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

bool solve(int n, int col) {
    if (col >= n) return true;

    for (int i = 0; i < n; i++) {
        if (issafe(i, col, n)) {
            board[i][col] = 1;
            if (solve(n, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void print(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    struct timeval start, end;
    gettimeofday(&start, NULL);
    if (solve(n, 0)) {
        gettimeofday(&end, NULL);
        print(n);
    } else {
        gettimeofday(&end, NULL);
        printf("Solution does not exist\n");
    }

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long total_microseconds = seconds * 1000000 + microseconds;
    printf("Time taken: %ld microseconds\n", total_microseconds);

    return 0;
}

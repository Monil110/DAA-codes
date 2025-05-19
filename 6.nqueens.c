#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

#define N 10
int board[N][N];
int solutionCount = 0;

bool issafe(int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) return false;
    }
    return true;
}

void print(int n) {
    printf("Solution %d:\n", ++solutionCount);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int n, int col) {
    if (col >= n) {
        print(n);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (issafe(i, col, n)) {
            board[i][col] = 1;
            solve(n, col + 1); 
            board[i][col] = 0; 
        }
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

    solve(n, 0);

    gettimeofday(&end, NULL);

    double time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    printf("Total solutions: %d\n", solutionCount);
    printf("Time taken: %.0lf microseconds\n", time);

    return 0;
}

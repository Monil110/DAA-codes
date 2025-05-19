#include <stdio.h>
#include <sys/time.h>

int moves = 0;

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        moves++;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    moves++;
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    towerOfHanoi(n, 'A', 'C', 'B');

    gettimeofday(&end, NULL);

    double timeTaken = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    printf("Total moves: %d\n", moves);
    printf("Time taken: %.8f microseconds\n", timeTaken);

    return 0;
}

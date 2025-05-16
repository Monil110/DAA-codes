#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define max 100
int adj[max][max];
int indeg[max];
int queue[max], front = 0, rear = 0, n;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int isempty() {
    return front == rear;
}

void ts() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) enqueue(i);
    }
    while (!isempty()) {
        int v = dequeue();
        printf("%d ", v);
        count++;
        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                indeg[i]--;
                if (indeg[i] == 0) enqueue(i);
            }
        }
    }
    if (count != n) {
        printf("Graph has cycle, topological sort not possible\n");
    }
}

void cind() {
    for (int i = 0; i < n; i++) {
        indeg[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i]) indeg[i]++;
        }
    }
}

int main() {
    int edges, src, dest;
    struct timeval start, end;

    printf("Enter the no of vertices: ");
    scanf("%d", &n);
    printf("Enter the no of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < edges; i++) {
        printf("Enter the edge from to : ");
        scanf("%d %d", &src, &dest);
        src--; dest--;
        adj[src][dest] = 1;
    }

    cind();

    gettimeofday(&start, NULL);  // Start time

    printf("Topological sort is : ");
    ts();

    gettimeofday(&end, NULL);    // End time

    long seconds = end.tv_sec - start.tv_sec;
    long micros = end.tv_usec - start.tv_usec;
    long total_microseconds = seconds * 1000000 + micros;

    printf("\nTime taken: %ld microseconds\n", total_microseconds);

    return 0;
}

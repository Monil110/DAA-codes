#include <stdlib.h>
#include <stdio.h>

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
    printf("Enter the no of vertices: ");
    scanf("%d", &n);
    printf("Enter the no of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < edges; i++) {
        printf("Enter the edge from to : ");
        scanf("%d %d", &src, &dest);
        src--;
        dest--;
        adj[src][dest] = 1;
    }
    cind();
    printf("Topological sort is : ");
    ts();
    return 0;
}
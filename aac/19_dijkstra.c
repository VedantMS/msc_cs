#include <stdio.h>

void min(int (*pq)[2], int front, int rear) {
    if (front != rear) {
        int index = front, num = pq[front][0];

        for (int i = front + 1; i < rear; i++) {
            if (pq[i][0] < num) {
                index = i;
                num = pq[i][0];
            }
        }

        int temp = pq[front][0];
        pq[front][0] = pq[index][0];
        pq[index][0] = temp;

        temp = pq[front][1];
        pq[front][1] = pq[index][1];
        pq[index][1] = temp;
    }
}

void dijkstra(int n, int (*adj)[n], int *dist, int source) {
    dist[source] = 0;

    int pq[100][2], front = 0, rear = 0;
    
    //  dist, node
    pq[rear][0] = 0;
    pq[rear][1] = source;
    rear++;

    while (front != rear) {
        min(pq, front, rear);

        int d = pq[front][0], u = pq[front][1];
        front++;
        
        if (d > dist[u]) {
            continue;
        }

        // relax
        for (int i = 0; i < n; i++) {
            if (d + adj[u][i] < dist[i]) {
                dist[i] = d + adj[u][i];
                
                pq[rear][0] = d + adj[u][i];
                pq[rear][1] = i;
                
                rear++;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter Total Nodes: ");
    scanf("%d", &n);

    int adj[n][n], dist[n];
    
    printf("Enter Adjacency Matrix: ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);

            if (i != j && adj[i][j] == 0) {
                adj[i][j] = 1000;
            }
        }
        
        dist[i] = 1000;
    }

    dijkstra(n, adj, dist, 0);

    printf("Distance from Source: \n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", dist[i]);
    }

    return 0;
}
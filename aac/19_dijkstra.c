#include <stdio.h>

int main() {
    int n;

    printf("Enter Total Nodes: ");
    scanf("%d", &n);

    int adj[n][n], visited[n], dist[n];
    
    printf("Enter Adjacency Matrix: ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);

            if (i != j && adj[i][j] == 0) {
                adj[i][j] = 100;
            }
        }

        visited[i] = 0;
        
        dist[i] = 1000;
    }

    dist[0] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == 1000) {
            break;
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] > 0 && !visited[v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    printf("Distance from Source: \n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", dist[i]);
    }

    return 0;
}
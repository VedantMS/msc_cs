#include <stdio.h>

int main() {
    int n;

    printf("Enter Total Nodes: ");
    scanf("%d", &n);

    int adj[n][n];
    
    printf("Enter Adjacency Matrix: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);

            if (adj[i][j] == -1) {
                adj[i][j] = 1000;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != k && j != k) {
                    adj[i][j] = adj[i][j] < adj[i][k] + adj[k][j] ? adj[i][j] : adj[i][k] + adj[k][j];
                }
            }
        }
    }

    printf("Floyd Warshall Algorithm: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", adj[i][j]);
        }

        printf("\n");
    }

    return 0;
}

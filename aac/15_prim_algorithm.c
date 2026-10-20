#include <stdio.h>

int main() {
    int n;

    printf("Enter Total Nodes: ");
    scanf("%d", &n);

    int adj[n][n], cost[n];
    
    printf("Enter Adjacency Matrix: ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }

        cost[i] = 100;
    }

    int u = 0, ans = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[j] != 0 && adj[u][j] != 0 && cost[j] > adj[u][j]) {
                cost[j] = adj[u][j];
            }
        }

        int num = -1, a = 1000;

        for (int j = 0; j < n; j++) {
            if (cost[j] != 0 && cost[j] < a) {
                num = j;
                a = cost[j];
            }
        }

        ans += cost[num];

        cost[u] = 0;
        cost[num] = 0;

        u = num;
    }

    printf("Minimum Spanning Tree: %d \n", ans);

    return 0;
}
#include <stdio.h>

void sort(int (*edges)[3], int e) {
    int num = 0;
    
    for (int i = e - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (edges[j][0] > edges[j + 1][0]) {
                for (int k = 0; k < 3; k++) {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }
}

int main() {
    int n;

    printf("Enter Total Nodes: ");
    scanf("%d", &n);

    int adj[n][n], edges[100][3], a[n], e = 0;
    
    printf("Enter Adjacency Matrix: ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);

            if (adj[i][j] != 0) {
                edges[e][0] = adj[i][j];
                edges[e][1] = i;
                edges[e][2] = j;

                e++;
            }
        }

        a[i] = i;
    }

    sort(edges, e);

    int ans = 0;

    for (int i = 0; i < e; i++) {
        int u = edges[i][1], v = edges[i][2];

        if (a[u] != a[v]) {
            ans += edges[i][0];

            int num = a[v];

            for (int i = 0; i < n; i++) {
                if (a[i] == num) {
                    a[i] = u;
                }
            }
        }
    }

    printf("Minimum Spanning Tree: %d \n", ans);

    return 0;
}
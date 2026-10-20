#include <stdio.h>

int max_ratio(int index, int n, float *r) {    
    for (int i = index + 1; i < n; i++) {
        if (r[i] > r[index]) {
            index = i;
        }
    }

    return index;
} 

int main() {
    int n, m;

    printf("Enter Total Elements: ");
    scanf("%d", &n);

    printf("Enter Bag Size: ");
    scanf("%d", &m);

    int p[n], w[n];

    printf("Enter Profit ans Weights: \n");

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i], &w[i]);
    }

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }

            else if (w[i - 1] <= j) {
                dp[i][j] = p[i - 1] + dp[i - 1][j - w[i - 1]] > dp[i - 1][j] ? p[i - 1] + dp[i - 1][j - w[i - 1]] : dp[i - 1][j];
            }
        }
    }

    printf("Maximum Profit: %d \n", dp[n][m]);

    return 0;
}
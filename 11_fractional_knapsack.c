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
    int n;
    float m;

    printf("Enter Total Elements: ");
    scanf("%d", &n);

    printf("Enter Bag Size: ");
    scanf("%f", &m);

    float p[n], w[n], r[n];

    printf("Enter Profit ans Weights: \n");

    for (int i = 0; i < n; i++) {
        scanf("%f%f", &p[i], &w[i]);
        r[i] = p[i] / w[i];
    }

    float ans = 0;

    for (int i = 0; i < n; i++) {
        int index = max_ratio(i, n, r);

        float temp = r[i];
        r[i] = r[index];
        r[index] = temp;
        
        temp = p[i];
        p[i] = p[index];
        p[index] = temp;

        temp = w[i];
        w[i] = w[index];
        w[index] = temp;

        if (w[i] <= m) {
            m -= w[i];
            ans += p[i];
        }

        else {
            ans += p[i] * (m / w[i]);
            m = 0;
            break;
        }
    }

    printf("Maximum Profit: %f \n", ans);

    return 0;
}
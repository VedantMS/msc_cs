#include <stdio.h>

float pow(float x, int n) {
    if (n == 0) {
        return 1;
    }

    float half = pow(x, n / 2);

    if (n % 2 == 0) {
        return half * half;
    }

    else {
        return half * half * x;
    }
}

int main() {
    float x;
    int n;
    
    printf("Enter Base and Power: ");
    scanf("%f%d", &x, &n);

    printf("%f^%d: %f \n", x, n, pow(x, n));

    return 0;
}
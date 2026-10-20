#include <stdio.h>

int partition(int *a, int left, int right) {
    int pivot = left++;
    
    while (left <= right) {
        while (left <= right && a[left] < a[pivot]) {
            left++;
        }

        while (left <= right && a[right] > a[pivot]) {
            right--;
        }

        if (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;

            left++;
            right--;
        }
    }

    int temp = a[pivot];
    a[pivot] = a[right];
    a[right] = temp;

    return right;
}

void quick_sort(int *a, int left, int right) {
    if (left < right) {
        int pi = partition(a, left, right);

        quick_sort(a, left, pi - 1);
        quick_sort(a, pi + 1, right);
    }
}

int main() {
    int n;

    printf("Enter Total Elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter Elements: \n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quick_sort(a, 0, n - 1);

    printf("Sorted Array: \n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}

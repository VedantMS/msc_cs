#include <stdio.h>

void merge(int *a, int l1, int r1, int l2, int r2) {
    int arr[r1 - l1 + r2 - l2 + 2], num = l1, index = 0;
    
    while (l1 <= r1 && l2 <= r2) {
        arr[index++] = a[l1] < a[l2] ? a[l1++] : a[l2++];
    }

    while (l1 <= r1) {
        arr[index++] = a[l1++];
    }

    while (l2 <= r2) {
        arr[index++] = a[l2++];
    }

    index = 0;

    for (int i = num; i <= r2; i++) {
        a[i] = arr[index++];
    }
}

void merge_sort(int *a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);

        merge(a, left, mid, mid + 1, right);
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

    merge_sort(a, 0, n - 1);

    printf("Sorted Array: \n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

bool dia(int r, int c, int n, char (*mat)[n]) {
    // left
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (mat[i][j] == 'Q') {
            return 1;
        }
    }

    // right
    for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
        if (mat[i][j] == 'Q') {
            return 1;
        }
    }

    return 0;
}

bool queens(int index, int n, char (*mat)[n], int *col) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c\t", mat[i][j]);
            }

            printf("\n");
        }

        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i] && !dia(index, i, n, mat)) {
            mat[index][i] = 'Q';
            col[i] = 1;

            if (queens(index + 1, n, mat, col)) {
                return 1;
            }

            mat[index][i] = '.';
            col[i] = 0;
        }
    }

    return 0;
}

int main() {
    int n;
    
    printf("Enter Dimension: ");
    scanf("%d", &n);

    char mat[n][n];
    int col[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = '.';
        }

        col[i] = 0;
    }

    if (!queens(0, n, mat, col)) {
        printf("N Queens Not Possible. \n");
    }

    return 0;
}
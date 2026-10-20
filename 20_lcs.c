#include <stdio.h>
#include <string.h>

int main() {
    char str1[10], str2[10];

    printf("Enter Strings: \n");
    scanf("%s%s", str1, str2);

    int n1 = strlen(str1), n2 = strlen(str2), lcs[n1 + 1][n2 + 1];

    for (int i = 0; i <= n1; i++) {
        lcs[i][0] = 0;
    }

    for (int i = 0; i <= n2; i++) {
        lcs[0][i] = 0;
    }

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i - 1] == str2[j - 1]) {       // index of str1 and str2 -> -1
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }

            else {
                lcs[i][j] = lcs[i][j - 1] > lcs[i - 1][j] ? lcs[i][j - 1] : lcs[i - 1][j];
            }
        }
    }

    int i = n1, j = n2, n = lcs[n1][n2];
    char ans[n + 1];
    ans[n] = '\0';

    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            ans[--n] = str1[i - 1];
            i--;
            j--;
        }

        else if (lcs[i - 1][j] > lcs[i][j - 1]) {
            i--;
        }

        else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s \n", ans);

    return 0;
}
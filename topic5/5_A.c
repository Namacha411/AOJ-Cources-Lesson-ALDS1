#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    size_t n, q, i;
    int *A, *m, bit, sum;
    bool *isok;

    scanf("%lu", &n);
    A = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%lu", &q);
    m = (int *)malloc(sizeof(int) * q);
    for (i = 0; i < q; i++) {
        scanf("%d", &m[i]);
    }

    isok = (bool *)malloc(sizeof(bool) * q);
    for (i = 0; i < q; i++) {
        isok[i] = false;
    }
    for (bit = 0; bit < (1 << n); bit++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                sum += A[i];
            }
        }
        for (i = 0; i < q; i++) {
            if (sum == m[i]) {
                isok[i] = true;
            }
        }
    }

    for (i = 0; i < q; i++) {
        puts(isok[i] ? "yes" : "no");
    }
    free(A);
    free(m);
    free(isok);
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t n, q, i, j;
    int *S, *T, ans, key;

    scanf("%lu", &n);
    S = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    scanf("%lu", &q);
    T = (int *)malloc(sizeof(int) * q);
    for (i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }

    ans = 0;
    for (i = 0; i < q; i++) {
        /* liner search */
        key = T[i];
        for (j = 0; j < n; j++) {
            if (S[j] == key) {
                ans += 1;
                break;
            }
        }
    }

    printf("%d\n", ans);
    free(S);
    free(T);
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t i, n, q;
    int *S, *T, ans, ng, ok, mid, key;

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
        /* binary search */
        ng = -1; ok = n;
        key = T[i];
        while (1 < ok - ng) {
            mid = (ok + ng) / 2;
            if (key <= S[(size_t)mid]) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (S[(size_t)ok] == key) {
            ans += 1;
        }
    }

    printf("%d\n", ans);
    free(S);
    free(T);
    return EXIT_SUCCESS;
}
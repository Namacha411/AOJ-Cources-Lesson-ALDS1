
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG

bool check(int P, int k, int *w, size_t n) {
    size_t i;
    int count, tmp;

    count = 0;
    tmp = 0;
    for (i = 0; i < n; i++) {
        if (P < tmp + w[i]) {
#ifdef DEBUG
            printf("DEBUG> weight: %d\n", tmp);
#endif
            tmp = w[i];
            count += 1;
        } else {
            tmp += w[i];
        }
    }
#ifdef DEBUG
    printf("DEBUG> track: %d\n", count);
#endif
    return count < k;
}

int main() {
    size_t i, n, k;
    int *w, ng, ok, mid;

    scanf("%lu %lu", &n, &k);
    w = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    /* binary search */
    ng = -1; ok = (int)1e5 + 1;
    while (1 < ok - ng) {
        mid = (ok + ng) / 2;
#ifdef DEBUG
        printf("\nDEBUG> P: %d\n", mid);
#endif
        if (check(mid, k, w, n)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    printf("%d\n", ok);
    free(w);
    return EXIT_SUCCESS;
}
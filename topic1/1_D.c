#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t n, i;
    int *r, inf, min, max;

    inf = 1 << 30;

    scanf("%lu", &n);
    r = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    max = -inf;
    min = r[0];
    for (i = 1; i < n; i++) {
        max = (max < r[i] - min) ? r[i] - min : max;
        min = (r[i] < min) ? r[i] : min;
    }

    printf("%d\n", max);
    free(r);
    return EXIT_SUCCESS;
}
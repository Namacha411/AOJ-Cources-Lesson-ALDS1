#include <stdio.h>
#include <stdlib.h>

int intpow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

void swap(int *lhs, int *rhs) {
    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

void print(int *array, size_t n) {
    size_t i;

    for (i = n - 1; i > 0; i--) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[0]);
    return;
}

int insertionSort(int *array, size_t n, size_t g) {
    size_t i;
    int v, j, count;

    count = 0;
    for (i = g; i < n; i++) {
        v = array[i];
        j = i - (int)g;
        while (0 <= j && v < array[(size_t)j]) {
            array[(size_t)j + g] = array[(size_t)j];
            j = j - (int)g;
            count += 1;
        }
        array[(size_t)j + g] = v;
    }
    return count;
}

int shellSort(int *array, size_t n, int *G, size_t m) {
    int count, i;

    count = 0;
    for (i = (int)m - 1; i >= 0; i--) {
        count += insertionSort(array, n, G[(size_t)i]);
    }
    return count;
}

int main() {
    size_t n, i, m;
    int *array, count, G[100], tmp;

    scanf("%lu", &n);
    array = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    /* calc G */
    G[0] = 1;
    for (i = 1; i < 100; i++) {
        tmp = intpow(4, i) + 3 * intpow(2, i - 1) + 1;
        G[i] = tmp;
        if (tmp > (int)n) {
            m = i;
            break;
        }
    }

    count = shellSort(array, n, G, m);

    printf("%lu\n", m);
    print(G, m);
    printf("%d\n", count);
    for (i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
    free(array);
    return EXIT_SUCCESS;
}
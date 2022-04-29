#include <stdio.h>
#include <stdlib.h>

void swap(int *lhs, int *rhs) {
    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

void print(int *array, size_t n) {
    size_t i;

    printf("%d", array[0]);
    for (i = 1; i < n; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");
    return;
}

int insertionSort(int *array, size_t n, size_t g) {
    size_t i;
    int v, j, count;

    for (i = g; i < n; i++) {
        v = array[i];
        j = (int)(i - g);
        while (0 <= j && v < array[(size_t)j]) {
            array[(size_t)j + g] = array[(size_t)j];
            j = j - (int)g;
            count += 1;
        }
        array[(size_t)j + g] = v;
    }
    return count;
}

int shellSort(int *array, size_t n) {

}

int main() {
    size_t n, i;
    int *array, ans;

    scanf("%lu", &n);
    array = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    ans = selectionSort(array, n);

    print(array, n);
    printf("%d\n", ans);
    free(array);
    return EXIT_SUCCESS;
}
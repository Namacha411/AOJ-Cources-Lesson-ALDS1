#include <stdio.h>
#include <stdlib.h>

void print(int *array, size_t n) {
    size_t i;
    printf("%d", array[0]);
    for (i = 1; i < n; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");
    return;
}

void insertionSort(int *array, size_t n) {
    int v, j;
    size_t i;
    for (i = 1; i < n; i++) {
        v = array[i];
        j = i - 1;
        while (j >= 0 && array[(size_t)j] > v) {
            array[(size_t)j + 1] = array[(size_t)j];
            j -= 1;
        }
        array[(size_t)j + 1] = v;
        print(array, n);
    }
    return;
}

int main() {
    size_t n, i;
    int *array;

    scanf("%lu", &n);
    array = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    print(array, n);
    insertionSort(array, n);

    free(array);
    return EXIT_SUCCESS;
}
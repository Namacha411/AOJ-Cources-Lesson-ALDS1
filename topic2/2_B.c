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

int selectionSort(int *array, size_t n) {
    size_t i, j, min;
    int count;

    count = 0;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i; j < n; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
        if (i != min) {
            count += 1;
        }
    }
    return count;
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
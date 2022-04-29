#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int bubbbleSort(int *array, size_t n) {
    size_t j;
    int count;
    bool flag;

    count = 0;
    flag = true;
    while (flag) {
        flag = false;
        for (j = n - 1; j >= 1; j--) {
            if (array[j] < array[j - 1]) {
                swap(&array[j], &array[j - 1]);
                count += 1;
                flag = true;
            }
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

    ans = bubbbleSort(array, n);

    print(array, n);
    printf("%d\n", ans);
    free(array);
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>

const int inf = 1 << 30;

long merge(int *array, size_t left, size_t mid, size_t right) {
    size_t n1, n2, i, j, k;
    int *L, *R;
    long count = 0;

    n1 = mid - left;
    n2 = right - mid;
    L = (int *)malloc(sizeof(int) * (n1 + 1));
    R = (int *)malloc(sizeof(int) * (n2 + 1));
    for (i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (i = 0; i < n2; i++) {
        R[i] = array[mid + i];
    }
    i = j = 0;
    L[n1] = R[n2] = inf;
    for (k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i += 1;
        } else {
            array[k] = R[j];
            j += 1;
            count += n1 - i;
        }
    }
    free(L);
    free(R);
    return count;
}

long mergeSort(int *array, size_t left, size_t right) {
    size_t mid;
    long tmp = 0;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        tmp += mergeSort(array, left, mid);
        tmp += mergeSort(array, mid, right);
        tmp += merge(array, left, mid, right);
        return tmp;
    }
    return 0;
}

void print(int *array, size_t n) {
    size_t i;
    for (i = 0; i < n - 1; i++) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[n - 1]);
}

int main() {
    size_t n, i;
    int *S;
    long ans;

    scanf("%lu", &n);
    S = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    ans = mergeSort(S, 0, n);

    printf("%ld\n", ans);
    free(S);
    return EXIT_SUCCESS;
}
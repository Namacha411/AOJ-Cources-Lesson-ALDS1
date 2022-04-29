#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int n) {
    int i;
    if (n == 0 || n == 1) {
        return false;
    }
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    size_t n, i;
    int *array, ans;

    scanf("%lu", &n);
    array = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    ans = 0;
    for (i = 0; i < n; i++) {
        if (isPrime(array[i])) {
            ans += 1;
        }
    }

    printf("%d\n", ans);
    free(array);
    return EXIT_SUCCESS;
}
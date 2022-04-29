#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    int x, y, ans;
    scanf("%d %d", &x, &y);

    ans = gcd(x, y);

    printf("%d\n", ans);
    return EXIT_SUCCESS;
}
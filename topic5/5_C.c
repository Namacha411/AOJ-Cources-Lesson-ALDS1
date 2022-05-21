#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Point_t;

Point_t newPoint(double x, double y) {
    Point_t t;
    t.x = x;
    t.y = y;
    return t;
}

void print(Point_t point) {
    printf("%f %f\n", point.x, point.y);
    return;
}

void kochCurve(Point_t start, Point_t end, int depth) {
    Point_t s, t, u;

    if (depth == 0) {
        return;
    }
    s = newPoint((2.0 * start.x + end.x) / 3.0, (2.0 * start.y + end.y) / 3.0);
    u = newPoint((start.x + 2.0 * end.x) / 3.0, (start.y + 2.0 * end.y) / 3.0);
    t = newPoint(
        (u.x - s.x) * (1.0 / 2.0) - (u.y - s.y) * (sqrt(3.0) / 2.0) + s.x,
        (u.x - s.x) * (sqrt(3.0) / 2.0) + (u.y - s.y) * (1.0 / 2.0) + s.y
    );

    kochCurve(start, s, depth - 1);
    print(s);
    kochCurve(s, t, depth - 1);
    print(t);
    kochCurve(t, u, depth - 1);
    print(u);
    kochCurve(u, end, depth - 1);
    return;
}

int main() {
    int n;
    Point_t start, end;

    scanf("%d", &n);

    start = newPoint(0.0, 0.0);
    end = newPoint(100.0, 0.0);

    print(start);
    kochCurve(start, end, n);
    print(end);
    return EXIT_SUCCESS;
}
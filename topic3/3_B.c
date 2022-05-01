#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100001

typedef struct {
    char name[100];
    int time;
} Process;


Process queue[STACK_SIZE];
int front, back;

void enqueue(Process p) {
    queue[back++ % STACK_SIZE] = p;
}

Process dequeue() {
    return queue[front++ % STACK_SIZE];
}

int main() {
    size_t n, i;
    int q, now;
    Process tmp;

    scanf("%lu %d", &n, &q);
    for (i = 0; i < n; i++) {
        scanf("%s %d", tmp.name, &tmp.time);
        enqueue(tmp);
    }

    now = 0;
    do {
        tmp = dequeue();
        if (tmp.time <= q) {
            printf("%s %d\n", tmp.name, now + tmp.time);
            now += tmp.time;
        } else {
            tmp.time -= q;
            now += q;
            enqueue(tmp);
        }
    } while (front < back);
    return EXIT_SUCCESS;
}
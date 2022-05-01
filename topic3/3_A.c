#include <stdio.h>
#include <stdlib.h>

int stack[100];
int index = 0;

void push(int x) {
    stack[index++] = x;
}

int pop() {
    return stack[--index];
}

int main() {
    char buff[100], x;
    int a, b;

    while (scanf("%s", buff) != EOF) {
        x = buff[0];
        switch (x)
        {
        case '+':
            a = pop();
            b = pop();
            push(a + b);
            break;
        case '-':
            a = pop();
            b = pop();
            push(b - a);
            break;
        case '*':
            a = pop();
            b = pop();
            push(a * b);
            break;
        default:
            push(atoi(buff));
            break;
        }
    }

    printf("%d\n", pop());
    return EXIT_SUCCESS;
}
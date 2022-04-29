#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char card[3];
} Card;

void swap(Card *lhs, Card *rhs) {
    Card tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

void print(Card *array, size_t n) {
    size_t i;

    printf("%s", array[0].card);
    for (i = 1; i < n; i++) {
        printf(" %s", array[i].card);
    }
    printf("\n");
    return;
}

int bubbbleSort(Card *array, size_t n) {
    size_t j;
    int count;
    bool flag;

    count = 0;
    flag = true;
    while (flag) {
        flag = false;
        for (j = n - 1; j >= 1; j--) {
            if (array[j].card[1] < array[j - 1].card[1]) {
                swap(&array[j], &array[j - 1]);
                count += 1;
                flag = true;
            }
        }
    }
    return count;
}

int selectionSort(Card *array, size_t n) {
    size_t i, j, min;
    int count;

    count = 0;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i; j < n; j++) {
            if (array[j].card[1] < array[min].card[1]) {
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
    Card *cards, *bubble, *selection;

    scanf("%lu", &n);
    cards = (Card *)malloc(sizeof(Card) * n);
    bubble = (Card *)malloc(sizeof(Card) * n);
    selection = (Card *)malloc(sizeof(Card) * n);
    for (i = 0; i < n; i++) {
        scanf("%s", cards[i].card);
    }

    memcpy(bubble, cards, sizeof(Card) * n);
    memcpy(selection, cards, sizeof(Card) * n);
    bubbbleSort(bubble, n);
    selectionSort(selection, n);

    print(bubble, n);
    printf("Stable\n");
    print(selection, n);
    printf(memcmp(bubble, selection, sizeof(Card) * n) == 0 ? "Stable\n" : "Not stable\n");

    free(cards);
    free(bubble);
    free(selection);
    return EXIT_SUCCESS;
}
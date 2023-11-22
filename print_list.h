#ifndef PRINT_LIST_H
#define PRINT_LIST_H

typedef struct listint_t {
    int n;
    struct listint_t *next;
    struct listint_t *prev;
} listint_t;

void print_list(listint_t *list);

#endif

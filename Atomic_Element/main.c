//
//  main.c
//  Atomic_Element
//
//  Created by slava bily on 13.09.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct element { char name[16]; char symb[8]; double weight; } element;

typedef struct list { element data; struct list *next;} list;

int is_empty(const list *l) {
    return (l == NULL);
}

list *create_list(element d) {
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list *add_to_front(element d, list *h) {
    list *head = create_list(d);
    head -> next = h;
    return head;
}

list *array_to_list(element d[], int size) {
    list *head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title) {
    printf("%s\n", title);
    while (!is_empty(h)) {
        printf("%s :", h -> data.name);
        h = h -> next;
    }
}

int main() {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

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
    printf("%s\n ----------------------", title);
    while (!is_empty(h)) {
        printf("%s\t %s\t %lg\n", h -> data.name, h -> data.symb, h -> data.weight);
        h = h -> next;
    }
}

int main() {
    list list_of_atoms;
    list *head;
    element atom;
    int i;
    
    printf("Enter atom data, separated by tab: \t name\t simbol\t  weight\n");
    scanf("%s\t %s\t %lg", &atom.name, &atom.symb, &atom.weight);
    
    head = create_list(atom);
    
    for (i = 1; i <= 2; i++) {
        printf("Enter atom data, separated by tab: \t name\t simbol\t  weight\n");
        scanf("%s\t %s\t %lg", &atom.name, &atom.symb, &atom.weight);
     
        head = add_to_front(atom, head);
    }
    
    print_list(head, "List of atoms");
    
    
    
    
     
    return 0;
}

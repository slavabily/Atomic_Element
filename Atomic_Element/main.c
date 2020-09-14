//
//  main.c
//  Atomic_Element
//
//  Created by Vyacheslav Bily on 13.09.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// MARK: element and list structures declaration
typedef struct element { char name[16]; char symb[8]; double weight; } element;

typedef struct list { element data; struct list *next;} list;

// MARK: fuctions for operations with List
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

void print_list(list *h, char *title) {
    printf("\n%s\n ----------------------\n name\t simbol\t weight\n", title);
    while (!is_empty(h)) {
        printf("%s    %s   %lg\n", h -> data.name, h -> data.symb, h -> data.weight);
        h = h -> next;
    }
}

// MARK: Main program routing
int main() {
    // declaration of variables
    list *head;
    element atom;
    int i;
    
    // input of data and list creation
    printf("Enter 1st atom data, separated by tab: \t name\t simbol\t  weight\n");
    scanf("%s %s %lg", &atom.name, &atom.symb, &atom.weight);
    
    head = create_list(atom);
    
    for (i = 2; i <= 10; i++) {
        printf("Enter data of atom number %d:\n", i);
        scanf("%s    %s    %lg", &atom.name, &atom.symb, &atom.weight);
     
        head = add_to_front(atom, head);
    }
    
    // printing of atoms table
    print_list(head, "List of atoms");
   
    return 0;
}

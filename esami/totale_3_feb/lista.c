#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

node *newList(persona *pers) {
    node *head = (node*) malloc(sizeof *head);
    head->pers = pers;
    head->next = NULL;
    return head;
}

void appendToList(node *list, persona *pers) {
    node *last = list;
    while (last->next != NULL)
        last = last->next;
    
    node *new_node = (node*) malloc(sizeof *new_node);
    new_node->pers = pers;
    last->next = new_node;
}

void addToList(node *list, persona *pers, int idx) {
    if (idx < 0) {
        printf("Negative index passed to \"addToList()\", defaulted to 0");
        idx = 0;
    }

    node *curr = list;
    node *prev = list;
    int n = 0;
    while (curr->next != NULL && n < idx) {
        prev = curr;
        curr = curr->next;
        n++;
    }

    node *new_node = (node*) malloc(sizeof *new_node);    
    new_node->pers = pers;
    
    prev->next = new_node;
    new_node->next = curr;
}

void printList(node *list) {
    node *curr = list;
    while (curr != NULL) {
        persona *pers = curr->pers;
        printf("Codice fiscale: %s | Attività: %d %d %d\n", pers->codice_fiscale, pers->attivita[0],
                                                            pers->attivita[1], pers->attivita[2]);
        curr = curr->next;
    }
}

void freeList(node *head) {
    node *curr = head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        free(temp->pers);
        free(temp);
    }
}

persona* getPersona(char *codice, node *lista) {
    node *curr = lista;
    while (curr != NULL) {
        if (strcmp(curr->pers->codice_fiscale, codice) == 0)
            return curr->pers;
        curr = curr->next;
    }
    return NULL;
}
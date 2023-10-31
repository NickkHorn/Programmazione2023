#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

nodo* newList(char *targa) {
    nodo *head = malloc(sizeof *head);
    head->next = NULL;
    strcpy(head->targa, targa);
    head->accessi = 1; // dovrebbe andare bene per ora...
    return head;
}

void addToList(nodo *list, char *targa) {
    nodo *curr = list;
    while (curr->next != NULL)
        curr = curr->next;

    nodo *new_node = malloc(sizeof *new_node);
    new_node->next = NULL;
    strcpy(new_node->targa, targa);
    new_node->accessi = 1;
    curr->next = new_node;
}

void printList(nodo *lista) {
    nodo *curr = lista;
    while (curr != NULL) {
        printf("%s %d\n", curr->targa, curr->accessi);
        curr = curr->next;
    }
}

void freeList(nodo *list) {
    nodo *curr = list;
    while (curr != NULL) {
        nodo* prev = curr;
        curr = curr->next;
        free(prev);
    }   
}

nodo* get(nodo *lista, char *targa) {
    nodo *curr = lista;
    while (curr != NULL) {
        if (strcmp(curr->targa, targa) == 0)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

void scriviPrezzi(nodo *lista) {
    nodo *curr = lista;
    while (curr != NULL) {
        if (curr->accessi <= 5)
            printf("%s %.2f\n", curr->targa, 2.0f*curr->accessi);
        else if (curr->accessi <= 10)
            printf("%s %.2f\n", curr->targa, 1.9f*curr->accessi);
        else 
            printf("%s %.2f\n", curr->targa, 1.8f*curr->accessi);
        curr = curr->next;
    }

}
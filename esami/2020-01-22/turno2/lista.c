#include "lista.h"
#include "stdlib.h"
#include "stdio.h"

unsigned short int getVaccIdx(char v_type) {
    if (v_type == 'C') return 0;
    else if (v_type == 'E') return 1;
    return 2;
} 

nodo* newList(vaccinazione *v) {
    nodo* head = malloc(sizeof *head);
    head->n_chip = v->n_chip;
    unsigned short int vaccinazione_idx = getVaccIdx(v->v_type);
    head->vaccinazioni[0] = (vaccinazione_idx == 0);
    head->vaccinazioni[1] = (vaccinazione_idx == 1);
    head->vaccinazioni[2] = (vaccinazione_idx == 2);
    head->next = NULL;
    return head;
}

// ritorna NULL se l'index è oltre la grandezza della lista
nodo* get(nodo* head, int n_chip) {
    nodo* curr = head;
    while (curr != NULL && curr->n_chip != n_chip)
        curr = curr->next;
    return curr;
}

void addToList(nodo* head, int n_chip, char vaccinazione) {
    nodo* curr = head;
    while (curr->next != NULL) curr = curr->next;

    nodo* new_node = malloc(sizeof *new_node);
    new_node->n_chip = n_chip;
    unsigned short int vaccinazione_idx = getVaccIdx(vaccinazione);
    new_node->vaccinazioni[0] = (vaccinazione_idx == 0);
    new_node->vaccinazioni[1] = (vaccinazione_idx == 1);
    new_node->vaccinazioni[2] = (vaccinazione_idx == 2);
    new_node->next = NULL;
    
    curr->next = new_node;
}

void segnaVaccinazione(nodo* list, vaccinazione *v) {
    nodo* v_node = get(list, v->n_chip);
    if (v_node == NULL)
        addToList(list, v->n_chip, v->v_type);
    else {
        unsigned short int v_idx = getVaccIdx(v->n_chip);
        v_node->vaccinazioni[v_idx] = true;
    }
}

void printList(nodo* head) {
    nodo* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->n_chip);
        if (curr->vaccinazioni[0]) printf("cimurro ");
        if (curr->vaccinazioni[1]) printf("epatite ");
        if (curr->vaccinazioni[2]) printf("parvovirosi");
        printf("\n");
        curr = curr->next;
    }
}

void freeList(nodo* list) {
    nodo* curr;
    while (curr != NULL) {
        nodo* temp = curr;
        curr = curr->next;
        printf("Liberando la memoria del nodo con chip: %d", temp->n_chip);
        free(temp);
    }
}
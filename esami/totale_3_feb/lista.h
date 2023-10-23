#define LUNGHEZZA_CODICE_FISCALE 17

typedef struct Persona {
    char codice_fiscale[LUNGHEZZA_CODICE_FISCALE];
    int attivita[3]; // conto del numero delle attività utilizzate
    int negati;
} persona;

typedef struct Node {
    struct Node *next;
    persona *pers;
} node;

node* newList(persona *pers);
void appendToList(node *list, persona *pers);
void addToList(node *list, persona *pers, int idx);
void printList(node *list);
void freeList(node *head);
persona* getPersona(char *codice, node *lista);
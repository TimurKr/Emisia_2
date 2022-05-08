#include <stdio.h>
#include <stdlib.h>

typedef struct TWN{
    float data;
    struct TWN *prev;
    struct TWN *next;
}TWN;

typedef struct{
    TWN *cur;
}CTWL;

CTWL *ctwl_create_empty(void){

    // Create structure for ctwl
    CTWL *ctwl = malloc(sizeof(CTWL));
    if (ctwl == NULL){
        return NULL;
    }

    ctwl->cur = NULL;
    return ctwl;
}

CTWL *ctwl_create_random(unsigned int size){
    // Create structure for ctwl
    CTWL *ctwl = malloc(sizeof(CTWL));
    if (ctwl == NULL){
        return NULL;
    }

    // Create first node TWN in ctwl and set cursor to it
    TWN *first_TWN = malloc(sizeof(TWN));
    if (first_TWN == NULL){
        return NULL;
    }

    // Create all other TWNs
    ctwl->cur = first_TWN;
    for (int i = 0; i < size; i++){
        ctwl->cur->next = malloc(sizeof(TWN));              // Needs protections against error with destroy
        ctwl->cur->data = rand();
        ctwl->cur->next->prev = ctwl->cur;
        ctwl->cur = ctwl->cur->next;
    }

    // Link the end with the start
    ctwl->cur->next = first_TWN;
    first_TWN->prev = ctwl->cur;

    return ctwl;
}

void ctwl_destroy(CTWL *list){

}

void ctwl_print(CTWL *list){
    if (list->cur == NULL){
        printf("List is empty.\n");
        return;
    }
    printf("Cursor: %f\n", list->cur->data);

    TWN *aux_cur = list->cur->next;
    unsigned short int i = 1;
    while (aux_cur != list->cur){
        printf("Cursor + %d: %f\n", i, aux_cur->data);
        aux_cur = aux_cur->next;
        i++;
    }
}

int main() {
    CTWL *list = ctwl_create_random(20);
    ctwl_print(list);
}

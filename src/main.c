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


void ctwl_destroy(CTWL *list){

    TWN *aux_cur = list->cur;
    while (aux_cur->next != list->cur){
        aux_cur = aux_cur->next;
        free(aux_cur->prev);
    }

    free(aux_cur);
    free(list);
}


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
    first_TWN->data = rand();

    // Create all other TWNs
    ctwl->cur = first_TWN;
    for (int i = 0; i < size - 1; i++){

        ctwl->cur->next = malloc(sizeof(TWN));
        if (ctwl->cur->next == NULL){           // If malloc fails
            ctwl->cur->next = first_TWN;        // close ctwl,
            first_TWN->prev = ctwl->cur;

            ctwl_destroy(ctwl);                 // destroy it
            return NULL;                        // and return error
        }

        ctwl->cur->next->prev = ctwl->cur;
        ctwl->cur = ctwl->cur->next;
        ctwl->cur->data = rand();
    }

    // Link the end with the start
    ctwl->cur->next = first_TWN;
    first_TWN->prev = ctwl->cur;

    return ctwl;
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
    CTWL *list = ctwl_create_random(5);
    ctwl_print(list);
    ctwl_destroy(list);
}

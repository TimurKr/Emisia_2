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


void ctwl_cur_step_right(CTWL *list){
    list->cur = list->cur->next;
}

void ctwl_cur_step_left(CTWL *list){
    list->cur = list->cur->prev;
}


void ctwl_destroy(CTWL *list){

    // If list is empty
    if(list->cur == NULL){
        free(list);
        return;
    }

    // Destroy all TWNs one by one
    TWN *aux_cur = list->cur;
    while (aux_cur->next != list->cur){
        aux_cur = aux_cur->next;
        free(aux_cur->prev);
    }

    // When only the last one is left, destroy it and then the ctwl itself
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

    // Protection against empty list
    if (size == 0){
        return ctwl_create_empty();
    }

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
        ctwl_cur_step_right(ctwl);
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

    printf("Cursor: \t\t%f\n", list->cur->data);

    TWN *aux_cur = list->cur->next;
    unsigned short int i = 1;
    while (aux_cur != list->cur){
        printf("Cursor + %d: \t%f\n", i, aux_cur->data);
        aux_cur = aux_cur->next;
        i++;
    }
}


TWN *ctwl_insert_left(CTWL* list, float val){
    // Allocate memory
    TWN *ptr = malloc(sizeof(TWN));
    if (ptr == 0){
        return 0;
    }

    // Setup the TWN
    ptr->data = val;
    ptr->prev = list->cur->prev;
    ptr->next = list->cur;

    // Correct pointers to the TWN
    list->cur->prev->next = ptr;
    list->cur->prev = ptr;

    return ptr;
}

TWN *ctwl_insert_right(CTWL* list, float val){
    // Allocate memory
    TWN *ptr = malloc(sizeof(TWN));
    if (ptr == 0){
        return 0;
    }

    // Setup the TWN
    ptr->data = val;
    ptr->prev = list->cur;
    ptr->next = list->cur->next;

    // Correct pointers to the TWN
    list->cur->next->prev = ptr;
    list->cur->next = ptr;

    return ptr;
}


int main() {
    CTWL *list = ctwl_create_random(0);
    ctwl_print(list);
    ctwl_destroy(list);
}

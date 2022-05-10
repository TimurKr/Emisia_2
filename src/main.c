#include <stdio.h>
#include <stdlib.h>

typedef struct TWN{
    float data;
    struct TWN *prev;
    struct TWN *next;
}TWN;   //Ako fungujú tieto structy????????????????????????????????????????

typedef struct{
    TWN *cur;
}CTWL;

//---------------------Cursor Movement------------------------

void ctwl_cur_step_right(CTWL *list){
    list->cur = list->cur->next;
}

void ctwl_cur_step_left(CTWL *list){
    list->cur = list->cur->prev;
}

//---------------------Element Delete------------------------

char ctwl_delete(CTWL *list){           //Ako spraviť return values???????????????????????????????

    // Protection against empty lists
    if (list->cur == NULL){
        return 0;
    }
        // Protection against lists size 1
    else if (list->cur->next == list->cur){
        free(list->cur);
        list->cur = NULL;
        return 1;
    }

    // Correct neighbouring TWN pointers
    TWN *aux_cur = list->cur;
    aux_cur->next->prev = aux_cur->prev;
    aux_cur->prev->next = aux_cur->next;
    ctwl_cur_step_right(list);
    free(aux_cur);
    return 2;
}

//---------------------List Destroy------------------------

void ctwl_destroy(CTWL *list){

    // Keep deleting elements until none left
    while (ctwl_delete(list) != 0){}

    // Delete list itself
    free(list);

}

//---------------------List Create------------------------

CTWL *ctwl_create_empty(void){
    //Returns pointer to the created list or NULL if fails

    // Create structure for ctwl
    CTWL *ctwl = malloc(sizeof(CTWL));
    if (ctwl == NULL){
        return NULL;
    }

    ctwl->cur = NULL;
    return ctwl;
}

CTWL *ctwl_create_random(unsigned int size){
    //Returns pointer to the created list or NULL if fails

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
    first_TWN->data = (float) rand();

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
        ctwl->cur->data = (float) rand();
    }

    // Link the end with the start
    ctwl->cur->next = first_TWN;
    first_TWN->prev = ctwl->cur;

    return ctwl;
}

//---------------------List Print------------------------

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

//---------------------Element Insertion------------------------

TWN *ctwl_insert_left(CTWL* list, float val){
    // Allocate memory
    TWN *ptr = malloc(sizeof(TWN));
    if (ptr == 0){
        return 0;
    }

    // Protection against empty lists
    if (list->cur == NULL){
        // Set up the TWN
        ptr->data = val;
        ptr->prev = ptr;
        ptr->next = ptr;

        // Set cursor
        list->cur = ptr;
    }

    else {
        // Set up the TWN
        ptr->data = val;
        ptr->prev = list->cur->prev;
        ptr->next = list->cur;

        // Correct neighbouring TWN pointers
        list->cur->prev->next = ptr;
        list->cur->prev = ptr;
    }
    return ptr;
}

TWN *ctwl_insert_right(CTWL* list, float val){
    // Allocate memory
    TWN *ptr = malloc(sizeof(TWN));
    if (ptr == 0){
        return 0;
    }

    // Protection against empty lists
    if (list->cur == NULL){
        // Set up the TWN
        ptr->data = val;
        ptr->prev = ptr;
        ptr->next = ptr;

        // Set cursor
        list->cur = ptr;
    }

    else {
        // Set up the TWN
        ptr->data = val;
        ptr->prev = list->cur;
        ptr->next = list->cur->next;

        // Correct neighbouring TWN pointers
        list->cur->next->prev = ptr;
        list->cur->next = ptr;
    }
    return ptr;
}

//---------------------Interpolačná funkcia, samotné zadanie------------------------

char ctwl_interpolate_linear(CTWL* list){
    TWN *org_cur = list->cur;
    ctwl_cur_step_right(list);
    while(org_cur != list->cur){
        ctwl_print(list);
        printf("\n");
        ctwl_insert_left(list, ((list->cur->prev->data + list->cur->data)) / 2);
        ctwl_print(list);
        printf("\n");
        ctwl_cur_step_right(list);
    }
    ctwl_print(list);
    printf("\n");
    ctwl_insert_left(list, ((list->cur->prev->data + list->cur->data)) / 2);
    return 'O';
}



//---------------------Main------------------------


int main() {
    CTWL *list = ctwl_create_empty();
    ctwl_insert_left(list, 1);
    ctwl_insert_left(list, 2);
    ctwl_insert_left(list, 3);
    ctwl_insert_left(list, 4);
    ctwl_print(list);
    printf("\n");
    ctwl_interpolate_linear(list);
    ctwl_print(list);
    printf("\n");
}

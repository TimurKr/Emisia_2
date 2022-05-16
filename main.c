#include <stdio.h>
#include <stdlib.h>

#include "ctwl.h"

// Add define for return values

//---------------------Cursor Movement------------------------

void ctwl_cur_step_left(CTWL *list) {
    list->cur = list->cur->prev;
}

void ctwl_cur_step_right(CTWL *list) {
    list->cur = list->cur->next;
}

//---------------------Element Delete------------------------

char ctwl_delete(CTWL *list) {           //Ako spraviť return values???????????????????????????????

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

void ctwl_destroy(CTWL *list) {

    // Keep deleting elements until none left
    while (ctwl_delete(list) != 0){}

    // Delete list itself
    free(list);

}

//---------------------List Print------------------------

void ctwl_print(CTWL *list) {

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

    // Needs protection against short lists


    TWN *org_cur = list->cur;
    ctwl_cur_step_right(list);
    while(org_cur != list->cur){
        ctwl_insert_left(list, ((list->cur->prev->data + list->cur->data)) / 2);
        ctwl_cur_step_right(list);
    }
    ctwl_insert_left(list, ((list->cur->prev->data + list->cur->data)) / 2);
    return 'O';
}



//---------------------Main------------------------


int main() {
    CTWL *list = ctwl_create_random(10);
    ctwl_print(list);
    printf("\n");
    ctwl_interpolate_linear(list);
    ctwl_print(list);
    printf("\n");
}

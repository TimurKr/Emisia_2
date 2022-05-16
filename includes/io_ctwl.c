//
// Created by Timur Kramar on 16/05/2022.
//

#include "ctwl.h"

//---------------------List Print------------------------

void ctwl_print(CTWL *list) {

    if (list->cur == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Cursor: \t\t%f\n", list->cur->data);

    TWN *aux_cur = list->cur->next;
    unsigned short int i = 1;
    while (aux_cur != list->cur) {
        printf("Cursor + %d: \t%f\n", i, aux_cur->data);
        aux_cur = aux_cur->next;
        i++;
    }
}


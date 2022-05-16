//
// Created by Timur Kramar on 16/05/2022.
//

#include "ctwl.h"
#include <stdlib.h>

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
//
// Created by Timur Kramar on 16/05/2022.
//

#include "ctwl.h"

//---------------------Element Delete------------------------

char ctwl_delete(CTWL *list) {           //Ako spraviť return values???????????????????????????????

    TWN *aux_cur = list->cur;

    // Protection against empty lists
    if (list->cur == NULL) {
        return DELETE_ELEM_FAIL;
    }
        // Protection against lists size 1
    else if (list->cur->next == list->cur) {
        free(list->cur);
        list->cur = NULL;
        return DELETE_ELEM_SUCCESS;
    }

    // Correct neighbouring TWN pointers
    aux_cur->next->prev = aux_cur->prev;
    aux_cur->prev->next = aux_cur->next;
    ctwl_cur_step_right(list);
    free(aux_cur);
    return DELETE_ELEM_SUCCESS;
}

//---------------------List Destroy------------------------

void ctwl_destroy(CTWL *list) {

    // Keep deleting elements until none left
    while (ctwl_delete(list) != DELETE_ELEM_FAIL) {}

    // Delete list itself
    free(list);
}
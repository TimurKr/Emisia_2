//
// Created by Timur Kramar on 16/05/2022.
//

#include "ctwl.h"

//---------------------Interpolačná funkcia, samotné zadanie------------------------

char ctwl_interpolate_linear(CTWL *list) {

    if (list->cur == NULL){                         // if list is empty
        return CTWL_PROBLEM;
    } else if (list->cur == list->cur->next) {      // if length of list is 1
        return CTWL_PROBLEM;
    }

    TWN *org_cur = list->cur;
    ctwl_cur_step_right(list);
    while (org_cur != list->cur) {
        ctwl_insert_left(list, ((list->cur->prev->data + list->cur->data)) / 2);
        ctwl_cur_step_right(list);
    }
    ctwl_insert_left(list, ((list->cur->prev->data + list->cur->data)) / 2);
    return CTWL_OK;
}
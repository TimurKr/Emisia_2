//
// Created by Timur Kramar on 16/05/2022.
//

#include "ctwl.h"

//---------------------Cursor Movement------------------------

void ctwl_cur_step_left(CTWL *list) {
    if (list->cur == NULL){
        return;
    }
    list->cur = list->cur->prev;
}

void ctwl_cur_step_right(CTWL *list) {
    if (list->cur == NULL){
        return;
    }
    list->cur = list->cur->next;
}

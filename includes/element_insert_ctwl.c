//
// Created by Timur Kramar on 16/05/2022.
//

#include "ctwl.h"

//---------------------Element Insertion------------------------

TWN *ctwl_insert_left(CTWL *list, float val) {
    // Allocate memory
    TWN *ptr = malloc(sizeof(TWN));
    if (ptr == 0) {
        return 0;
    }

    // Protection against empty lists
    if (list->cur == NULL) {
        // Set up the TWN
        ptr->data = val;
        ptr->prev = ptr;
        ptr->next = ptr;

        // Set cursor
        list->cur = ptr;
    } else {
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

TWN *ctwl_insert_right(CTWL *list, float val) {
    // Allocate memory
    TWN *ptr = malloc(sizeof(TWN));
    if (ptr == 0) {
        return 0;
    }

    // Protection against empty lists
    if (list->cur == NULL) {
        // Set up the TWN
        ptr->data = val;
        ptr->prev = ptr;
        ptr->next = ptr;

        // Set cursor
        list->cur = ptr;
    } else {
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


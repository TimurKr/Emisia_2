//
// Created by Timur Kramar on 16/05/2022.
//

#include <stdlib.h>
#include "ctwl.h"

CTWL *ctwl_create_empty(void) {
    //Returns pointer to the created list or NULL if fails

    // Create structure for ctwl
    CTWL *ctwl = malloc(sizeof(CTWL));
    if (ctwl == NULL) {
        return NULL;
    }

    ctwl->cur = NULL;
    return ctwl;
}

CTWL *ctwl_create_random(unsigned int size) {
    //Returns pointer to the created list or NULL if fails

    // Protection against empty list
    if (size == 0) {
        return ctwl_create_empty();
    }

    // Create structure for ctwl
    CTWL *ctwl = malloc(sizeof(CTWL));
    if (ctwl == NULL) {
        return NULL;
    }

    // Create first node TWN in ctwl and set cursor to it
    TWN *first_TWN = malloc(sizeof(TWN));
    if (first_TWN == NULL) {
        return NULL;
    }
    first_TWN->data = (float) rand();

    // Create all other TWNs
    ctwl->cur = first_TWN;
    for (int i = 0; i < size - 1; i++) {

        ctwl->cur->next = malloc(sizeof(TWN));
        if (ctwl->cur->next == NULL) {           // If malloc fails
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
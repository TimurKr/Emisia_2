//
// Created by Timur Kramar on 16/05/2022.
//

#include <stdlib.h>
#include <stdio.h>

#define CREATE_CTWL_ERROR 0
#define INSERT_ELEM_ERROR 0

#define DELETE_ELEM_ERROR_LIST_LEN_0 0
#define DELETE_ELEM_NONE_LEFT 1
#define DELETE_ELEM_SUCCESS 2


typedef struct TWN {
    float data;
    struct TWN *prev;
    struct TWN *next;
} TWN;

typedef struct CTWL {
    TWN *cur;
} CTWL;

CTWL *ctwl_create_empty(void);

CTWL *ctwl_create_random(unsigned int size);

void ctwl_destroy(CTWL *list);

char ctwl_delete(CTWL *list);

void ctwl_cur_step_right(CTWL *list);

void ctwl_cur_step_left(CTWL *list);

void ctwl_print(CTWL *list);

TWN *ctwl_insert_left(CTWL *list, float val);

TWN *ctwl_insert_right(CTWL *list, float val);

char ctwl_interpolate_linear(CTWL *list);



//
// Created by Timur Kramar on 16/05/2022.
//

typedef struct TWN{
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

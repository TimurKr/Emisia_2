#include <stdio.h>
#include <stdlib.h>

typedef struct TWN{
    float data;
    struct TWN *prev;
    struct TWN *next;
}TWN;

typedef struct{
    TWN *cur;
}CTWL;

CTWL *ctwl_create_empty(void){

    // Create structure for ctwl
    CTWL *ctwl = malloc(sizeof(CTWL));
    if (ctwl == NULL){
        return NULL;
    }

    ctwl->cur = NULL;
    return ctwl;
}

CTWL *ctwl_create_random(unsigned int size){
    // Create structure for ctwl
    CTWL *ctwl = malloc(sizeof(CTWL));
    if (ctwl == NULL){
        return NULL;
    }

    // Create first node TWN in ctwl and set cursor to it
    TWN *first_TWN = malloc(sizeof(TWN));
    if (first_TWN == NULL){
        return NULL;
    }


    ctwl->cur = first_TWN;
    // Create all other TWN
    for (int i = 0; i < size; i++){
        ctwl->cur->next = malloc(sizeof(TWN));
        ctwl->cur->next->prev = ctwl->cur;
        ctwl->cur = ctwl->cur->next;
    }

    // Link the end to the start
    ctwl->cur->next =

    return ctwl;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}

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
    ctwl->cur = malloc(sizeof(TWN));
    if (ctwl->cur == NULL){
        return NULL;
    }

    for (int i = 0; i < size; i++){
        ctwl->cur = malloc(sizeof(TWN));
    }

    return ctwl;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}

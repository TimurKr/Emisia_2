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

}

CTWL *ctwl_create_random(unsigned int size){

}

int main() {
    printf("Hello, World!\n");
    return 0;
}

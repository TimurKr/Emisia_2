#include <stdio.h>

typedef struct TWN{
    float data;
    struct TWN *prev;
    struct TWN *next;
}TWN;

typedef struct{
    TWN *cur;
}CTWL;


int main() {
    printf("Hello, World!\n");
    return 0;
}

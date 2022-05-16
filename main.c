#include "ctwl.h"

int main() {
    CTWL *list = ctwl_create_random(10);
    ctwl_print(list);
    printf("\n");
    ctwl_interpolate_linear(list);
    ctwl_print(list);
    printf("\n");
    printf(".");
}

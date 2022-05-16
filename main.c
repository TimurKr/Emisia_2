#include "ctwl.h"

//---------------------Interpolačná funkcia, samotné zadanie------------------------

char ctwl_interpolate_linear(CTWL *list) {

    // Needs protection against short lists

    TWN *org_cur = list->cur;
    ctwl_cur_step_right(list);
    while (org_cur != list->cur) {
        ctwl_insert_left(list, ((list->cur->prev->data + list->cur->data)) / 2);
        ctwl_cur_step_right(list);
    }
    ctwl_insert_left(list, ((list->cur->prev->data + list->cur->data)) / 2);
    return 'O';
}


int main() {
    CTWL *list = ctwl_create_random(10);
    ctwl_print(list);
    printf("\n");
    ctwl_interpolate_linear(list);
    ctwl_print(list);
    printf("\n");
    printf(".");
}

#include "../src/list/list.h"
#include <stdlib.h>


int main()
{
    t_node* a;
    t_node* b;
    t_node* ops;

    a = NULL;
    b = NULL;
    push(&a, 7);
    push(&a, 8);
    push(&a, 1);
    push(&a, 2);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);

    merge_sort(&a, &b, &ops);
    clear(&a);
    return (0);
}
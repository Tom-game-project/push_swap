#include "../src/list/list.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
    t_node* a;
    t_node* b;
    t_node* ops;

    a = NULL;
    b = NULL;
    ops = NULL;
    push(&a, 7);
    push(&a, 8);
    push(&a, 1);
    push(&a, 2);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);

    printf("%d\n", pop(&a, 6));
    printf("list\n");
    print_list(&a);

    merge_sort(&a, &b, &ops);
    output_all_ops(&ops);
    
    clear(&a);
    return (0);
}

#include <stdio.h>
#include "list.h"

void print_list(t_node** parent){
    t_node* tmp_node_p;

    tmp_node_p = *parent;
    while (tmp_node_p != NULL)
    {
        printf("%d",tmp_node_p->i32_data);
        tmp_node_p = tmp_node_p->back_p;
    }
    printf("hello world");
}
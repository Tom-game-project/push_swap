#include "src/list/list.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    t_node* node;

    node= NULL;
    push(&node,1);
    push(&node,2);
    push(&node,3);
    push(&node,4);
    assignment(&node,4,100);
    print_ptr(&node);
    return (0);
}
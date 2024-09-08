
#include "src/list/list.h"
#include <stdlib.h>
#include "stdio.h"
#include <assert.h>

/// @brief
/// @return 
int main(){
    t_node *node;

    // push(&node, 1);
    // print_list(&node);
    node = NULL;
    push(&node, 1);
    push(&node, 2);
    push(&node, 3);
    insert(&node,2,100);
    printf("length %d\n", len(node));
    // print_list(&node);
    print_ptr(&node);
    // assert(2 == len(node));
    return (0);
}
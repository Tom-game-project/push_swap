
#include "src/list/list.h"
#include <stdlib.h>


int main(){
    t_node *node;

    // push(&node, 1);

    // print_list(&node);
    node = NULL;
    push(&node, 1);
    push(&node, 2);
    print_list(&node);
    return (0);
}
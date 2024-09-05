
#include "src/list/list.h"

int main(){
    t_node *node;

    // push(&node, 1);

    // print_list(&node);
    node = init_node(1);
    print_list(&node);
    return (0);
}
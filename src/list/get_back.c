#include "list.h"
#include <stdlib.h>

t_node* get_back(t_node *node_p){
    if (node_p == NULL)
        return (node_p);
    while (node_p -> back_p != NULL)
        node_p = node_p->back_p;        
    return (node_p);
}

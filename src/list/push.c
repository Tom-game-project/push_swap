#include "list.h"
#include <stdlib.h>

/// @brief malloc if error return 1 otherwise 0
/// @param i32_data 
/// @return 
int push(t_node** parent_p,int i32_data){
    t_node* back_node_p;
    t_node* new_node_p;

    new_node_p = init_node(i32_data);
    if (new_node_p == NULL)
        return (1);// error
    back_node_p = get_back(*parent_p);
    if (back_node_p == NULL)
    {
        *parent_p = new_node_p;
        return (0);
    }
    back_node_p->back_p = new_node_p;
    new_node_p->pre_p = back_node_p;
    return (0);
}
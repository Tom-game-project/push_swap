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

int heappush(t_node** parent_p,int i32_data){
    int current_index;
    int parent_index;
    t_node* parent_node;

    push(parent_p, i32_data);
    current_index = len(*parent_p) - 1;
    while (0 < current_index)
    {
        parent_index = (current_index - 1) / 2;
        parent_node = get_ptr(*parent_p, parent_index);
        if (i32_data < parent_node -> i32_data)
        {
            assignment(parent_p, current_index, parent_node -> i32_data);
            current_index = parent_index;
            continue;
        }
        break;
    }
    assignment(parent_p, current_index, i32_data);
    return (0);
}

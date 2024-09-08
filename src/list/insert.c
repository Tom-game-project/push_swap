#include "list.h"
#include "private_list.h"
#include <stdlib.h>


/// @brief 
/// @param node_p 
/// @param index 
/// @param value 
/// @return 
int insert(t_node **node_p_p, int index, int value){
    t_node* target_node;
    t_node* new_node;
    t_node* first_tmp;

    first_tmp = *node_p_p;
    target_node = get_raw_ptr(node_p_p,index);
    new_node = init_node(value);
    new_node->back_p = target_node;
    if (target_node != NULL){
        new_node->pre_p = target_node->pre_p;
        target_node->pre_p = new_node;
    }
    if (0 < index)
    {
        new_node->pre_p->back_p = new_node;
        *node_p_p = first_tmp;
    }
    else
        *node_p_p = new_node;
    return (0);
}


#include "list.h"
#include "private_list.h"
#include <stdlib.h>

/// @brief return head data and remove it
/// @return 
int pop(t_node **node_p_p,int index){
    int rvalue;
    t_node* head_p;

    head_p = pop_index_elem(node_p_p,index);
    rvalue = head_p->i32_data;
    free(head_p);
    return (rvalue);
}

/// @brief you must free returned object by yourself
/// @param node_p_p 
/// @return 
t_node* pop_elem(t_node **node_p_p)
{
    t_node* head_p;

    head_p = *node_p_p;
    if (head_p == NULL)
        return (NULL);// error
    *node_p_p = head_p->back_p;
    if (head_p -> back_p != NULL)
    {
        head_p->back_p->pre_p = NULL;
        head_p->back_p = NULL;
    }
    return(head_p);
}


/// @brief you must free returned object by yourself
///        values outside the range are undefined
/// @param node_p_p 
/// @param index 
/// @return 
t_node* pop_index_elem(t_node** node_p_p,int index)
{
    t_node* r_node;
    t_node* first_node;

    if (index == 0)
        return (pop_elem(node_p_p));
    first_node = *node_p_p;
    r_node = get_raw_ptr(node_p_p,index);
    r_node->pre_p->back_p = r_node->back_p;
    if (r_node->back_p != NULL)
        r_node->back_p->pre_p = r_node->pre_p;
    r_node->pre_p = r_node->back_p = NULL;
    *node_p_p = first_node;
    return (r_node);
}


int __pop_swap_helper(t_node** node_p_p,int current_index, int child_index)
{
    set_num(node_p_p, current_index, get_elem(*node_p_p,child_index));
    return (child_index);
}

int __pop_proc(t_node** node_p_p, int last_index)
{
    int current_index;
    int current_item;
    int child_index;

    current_item = get_elem(*node_p_p, current_index = 0);
    while ((child_index = current_index * 2 + 1) <= last_index)
    {
        if (last_index <= child_index)
        {
            if (get_elem(*node_p_p,child_index) < current_item)
                current_index = __pop_swap_helper(node_p_p, current_index, child_index);
            break;
        }
        if (get_elem(*node_p_p, child_index + 1) < current_item && \
        get_elem(*node_p_p, child_index + 1) < get_elem(*node_p_p, child_index))
            current_index = __pop_swap_helper(node_p_p, current_index, child_index + 1);
        else if (get_elem(*node_p_p, child_index + 1) < current_item || get_elem(*node_p_p, child_index) < current_item)
            current_index = __pop_swap_helper(node_p_p, current_index, child_index);
        else
            break;
    }
    return (current_index);
}

/// @brief remove first element of heap data
///        you must check the first element exist
/// @param node_p_p 
/// @return 
int heappop(t_node** node_p_p)
{
    int rvalue;
    int last_index;
    int new_head;

    rvalue = pop(node_p_p, 0);
    if (len(*node_p_p) == 0)
        return rvalue;
    last_index = len(*node_p_p) - 1;
    new_head = pop(node_p_p,last_index);
    insert(node_p_p,0,new_head);
    set_num(node_p_p, __pop_proc(node_p_p, last_index),new_head);
    return (rvalue);
}


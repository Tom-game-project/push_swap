#include "list.c"
#include "private_list.h"
#include <stdlib.h>

/// @brief return head data and remove it
///        
/// @return 
int pop(t_node **node_p_p){
    int i32_data;
    t_node* head_p;

    head_p = *node_p_p;
    if (head_p == NULL){
        return (404);// error
    }
    i32_data = head_p -> i32_data;
    if (head_p -> back_p != NULL){
        head_p->back_p->pre_p = NULL;
    }
    return(i32_data);
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
    r_node->back_p->pre_p = r_node->pre_p;
    r_node->pre_p = r_node->back_p = NULL;
    *node_p_p = first_node;
    return (r_node);
}

/// @brief remove first element of heap data
/// @param node_p_p 
/// @return 
// int heappop(t_node** node_p_p){
//     int rvalue = 
// }
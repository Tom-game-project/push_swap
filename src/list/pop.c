#include "list.c"
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

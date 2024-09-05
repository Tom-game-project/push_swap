#include "list.h"
#include <stdlib.h>


/// @brief return type Result<t_node,NULL>
/// @param i32_data 
/// @return 
t_node* init_node(int i32_data){
    t_node* node;

    node = (t_node*)malloc(sizeof(t_node*));
    if (node == NULL)
        return (NULL);
    node->back_p=NULL;
    node->pre_p=NULL;
    node->i32_data = i32_data;
    return (node);
}
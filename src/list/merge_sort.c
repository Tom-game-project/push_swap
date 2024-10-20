#include <stdlib.h>
#include "list.h"


/// @brief 
/// @param f from
/// @param t to
static void move_stack(t_node **f, t_node **t)
{
    int i;

    i = 1;
    if (get_elem(*f, 0) * i < get_elem(*f, len(*f) - 1) * i)
        insert(t, 0, pop(f, len(*f) - 1));
    else
        insert(t, 0, pop(f, 0));
    while (*f != NULL){
        if (get_elem(*f, 0) * i < get_elem(*t, 0) * i)
        {
            if (get_elem(*f, 0) * i < get_elem(*f, len(*f) - 1) * i && \
                get_elem(*f, len(*f) - 1) * i < get_elem(*t, 0) * i)
                insert(t, 0, pop(f, len(*f) - 1));
            else
                insert(t, 0, pop(f, 0));
        }
        else 
            i *= -1;
    }
}

void merge_sort(t_node **node_a,t_node **node_b)
{
    while (/*not*/ !is_sorted (*node_a))
    {
        move_stack(node_a, node_b); // from node_a to node_b
        move_stack(node_b, node_a); // from node_b to node_a
    }
}
#include <stdlib.h>
#include "list.h"


static void move_stack(t_node **a, t_node **b)
{
    int i;
    
    i = 1;
    if (get_elem(*a, 0) * i < get_elem(*a, len(*a) - 1) * i)
        insert(b, 0, pop(a, len(*a) - 1));
    else
        insert(b, 0, pop(a, 0));
    while (*a != NULL){
        if (get_elem(*a, 0) * i < get_elem(*b, 0) * i)
        {
            if (get_elem(*a, 0) * i < get_elem(*a, len(*a) - 1) * i && \
                get_elem(*a, len(*a) - 1) * i < get_elem(*b, 0) * i)
                insert(b, 0, pop(a, len(*a) - 1));
            else
                insert(b, 0, pop(a, 0));
        }
        else 
            i *= -1;
    }
}

static int is_sorted(t_node *ra)
{
    int a_length;
    int i;

    a_length = len(ra);
    i = 0;
    while (i < a_length - 1)
    {
        if (get_elem(ra, i) < get_elem(ra, i + 1))
            i++;
        else
            return (0);
    }
    return (1);
}

void merge_sort(t_node **node_a,t_node **node_b)
{
    while (/*not*/ !is_sorted (*node_a))
    {
        move_stack(node_a, node_b);
        move_stack(node_b, node_a);
    }
}
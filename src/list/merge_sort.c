#include <stdlib.h>
#include "list.h"

#include "../../src/output/output.h"


/**
 * 最適化ルール
 * pa pb -> nop
 * pb pa -> nop
 * rra rrb -> rrr
 * rrb rra -> rrr
 */


static void push_end(t_node **f, t_node**t, char f_f, t_node **ops)
{
    insert(t, 0, pop(f, len(*f) - 1));
    if (f_f == 'a')
    {
        push(ops, RRA);
        push(ops, PB);
    }
    else
    {
        push(ops, RRB);
        push(ops, PA);
    }
}

static void push_head(t_node **f, t_node**t, char f_f, t_node **ops)
{
    insert(t, 0, pop(f, 0));
    if (f_f == 'a')
        push(ops, PB);
    else
        push(ops, PA);
}

static void push_second(t_node **f, t_node**t, char f_f, t_node **ops)
{
    insert(t, 0, pop(f, 1));
    if (f_f == 'a')
    {
        push(ops, SA);
        push(ops, PB);
    }
    else
    {
        push(ops, SB);
        push(ops, PA);
    }
}

/// @brief 
/// @param f from
/// @param t to
static void move_stack(t_node **f, t_node **t,char f_f, t_node** ops)
{
    int i;

    i = 1;
    if (get_elem(*f, 0) * i < get_elem(*f, len(*f) - 1) * i)
        push_end(f, t, f_f, ops);
    else
        push_head(f, t, f_f, ops);
    while (*f != NULL){
        if (get_elem(*f, 0) * i < get_elem(*t, 0) * i)
        {
            if (get_elem(*f, 0) * i < get_elem(*f, len(*f) - 1) * i && \
                get_elem(*f, len(*f) - 1) * i < get_elem(*t, 0) * i)
                push_end(f, t, f_f, ops);
            else
                push_head(f, t, f_f, ops);
        }
        else if (get_elem(*f, len(*f) - 1) * i < get_elem(*t, 0) * i)
            push_end(f, t,f_f, ops);
        else if (1 < len(*f) && get_elem(*f, 1) * i < get_elem(*t, 0) * i)
            push_second(f, t, f_f, ops);
        else
            i *= -1;
    }
}

void merge_sort(t_node **node_a,t_node **node_b, t_node **ops)
{
    while (/*not*/ !is_sorted (*node_a))
    {
        move_stack(node_a, node_b, 'a', ops); // from node_a to node_b
        move_stack(node_b, node_a, 'b', ops); // from node_b to node_a
    }
}
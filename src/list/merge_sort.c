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
#define SA 0
#define SB 1
#define SS 2

#define PA 3
#define PB 4

#define RA 5
#define RB 6
#define RR 7

#define RRA 8
#define RRB 9
#define RRR 10


static void push_end(t_node **f, t_node**t, char f_f)
{
    insert(t, 0, pop(f, len(*f) - 1));
    if (f_f == 'a')
    {
        put_str("rra\n");
        put_str("pb\n");
    }
    else
    {
        put_str("rrb\n");
        put_str("pa\n");
    }
}

static void push_head(t_node **f, t_node**t, char f_f)
{
    insert(t, 0, pop(f, 0));
    if (f_f == 'a')
        put_str("pb\n");
    else
        put_str("pa\n");
}

static void push_second(t_node **f, t_node**t, char f_f)
{
    insert(t, 0, pop(f, 1));
    if (f_f == 'a')
    {
        put_str("sa\n");
        put_str("pb\n");
    }
    else
    {
        put_str("sb\n");
        put_str("pa\n");
    }
}

/// @brief 
/// @param f from
/// @param t to
static void move_stack(t_node **f, t_node **t,char f_f)
{
    int i;

    i = 1;
    if (get_elem(*f, 0) * i < get_elem(*f, len(*f) - 1) * i)
        push_end(f, t, f_f);
    else
        push_head(f, t, f_f);
    while (*f != NULL){
        if (get_elem(*f, 0) * i < get_elem(*t, 0) * i)
        {
            if (get_elem(*f, 0) * i < get_elem(*f, len(*f) - 1) * i && \
                get_elem(*f, len(*f) - 1) * i < get_elem(*t, 0) * i)
                push_end(f, t, f_f);
            else
                push_head(f, t, f_f);
        }
        else if (get_elem(*f, len(*f) - 1) * i < get_elem(*t, 0) * i)
            push_end(f, t,f_f);
        else if (1 < len(*f) && get_elem(*f, 1) * i < get_elem(*t, 0) * i)
            push_second(f, t,f_f);
        else
            i *= -1;
    }
}

void merge_sort(t_node **node_a,t_node **node_b)
{
    while (/*not*/ !is_sorted (*node_a))
    {
        move_stack(node_a, node_b, 'a'); // from node_a to node_b
        move_stack(node_b, node_a, 'b'); // from node_b to node_a
    }
}
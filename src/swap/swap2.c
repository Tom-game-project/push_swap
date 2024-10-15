#include "../../src/output/output.h"


static void h_s_2(int index_a,int index_b,int stack_b_length)
{
    int i;

    i = 0;
    while (i < index_a + 1)
    {
        put_str("pa\n");
        i++;
    }
    i = 0;
    while (i < stack_b_length - index_b)
    {
        put_str("rrb\n");
        put_str("pa\n");
        put_str("ra\n");
        i++;
    }
}

static void m_h_s_2()
{
    put_str("pb\n");
    put_str("rb\n");
    put_str("rra\n");
    put_str("pb\n");
}

static void i_h_s_2(int index_a,int index_b, int stack_b_length)
{
    int i;

    i = 0;
    while (i < stack_b_length - index_b - 1)
    {
        put_str("rra\n");
        put_str("pb\n");
        put_str("rb\n");
        i++;
    }
    i = 0;
    while (i < index_a)
    {
        put_str("pb\n");
        i++;
    }
}

/// @brief  必要なステップ数 2 * (index_a + 1) + 6 * (stack_b_length - index_b)
/// @param index_a 
/// @param index_b 
void swap_stack_b_2(int index_a,int index_b, int stack_b_length)
{
    // pass
    h_s_2(index_a, index_b,stack_b_length);
    m_h_s_2();
    i_h_s_2(index_a, index_b, stack_b_length);
}

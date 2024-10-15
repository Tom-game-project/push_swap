
#include "../../src/output/output.h"


static void h_s_3(int index_a,int index_b)
{
    int i;

    i = 0;
    while (i < index_a)
    {
        put_str("pa\n");
        i++;
    }
    i = 0;
    while (i < index_b - index_a - 1)
    {
        put_str("sb\n");
        put_str("pa\n");
        i++;
    }
}

static void m_h_s_3()
{
    put_str("sb\n");
    put_str("rb\n");
}

static void i_h_s_3(int index_a,int index_b)
{
    int i;

    i = 0;
    while (i < index_b - index_a - 1)
    {
        put_str("pb\n");
        i++;
    }
    put_str("rrb\n");
    i = 0;
    while (i < index_a)
    {
        put_str("pb\n");
        i++;
    }
}

/// @brief  必要なステップ数 
/// @param index_a 
/// @param index_b 
void swap_stack_b_3(int index_a,int index_b)
{
    // pass
    h_s_3(index_a,index_b);
    m_h_s_3();
    i_h_s_3(index_a, index_b);
}

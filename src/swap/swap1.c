#include "../../src/output/output.h"


static void h_s_1(int a,int b)
{
    int i;

    i = 0;
    while (i < b + 1)
    {
        put_str("rrb\n");
        put_str("pa\n");
        i++;
    }
    i = 0;
    while (i < a - b)
    {
        put_str("rrb\n");
        i++;
    }
}

static void m_h_s_1()
{
    put_str("pb\n");
    put_str("rb\n");
    put_str("pa\n");
}

static void i_h_s_1(int a,int b)
{
    int i;

    i = 0;
    while (i < a - b - 1)
    {
        put_str("rb\n");
        i++;
    }
    i = 0;
    while (i < b + 1)
    {
        put_str("pb\n");
        put_str("rb\n");
        i++;
    }
}

/// @brief  必要なステップ数 
/// @param index_a 
/// @param index_b 
void swap_stack_b_1(int index_a,int index_b, int stack_b_length)
{
    // pass
    int a;
    int b;

    a = stack_b_length - index_a - 1;
    b = stack_b_length - index_b - 1;
    h_s_1(a,b);
    m_h_s_1();
    i_h_s_1(a, b);
}
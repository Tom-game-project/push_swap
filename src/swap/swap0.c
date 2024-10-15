#include <stdio.h>


static void h_s_0(int index_a,int index_b)
{
    int i;

    i = 0;
    while (i < index_a + 1)
    {
        printf("pa\n");
        i++;
    }
    i = 0;
    while (i < index_b - index_a)
    {
        printf("rb\n");
        i++;
    }
}

static void m_h_s_0()
{
    printf("pb\n");
    printf("rrb\n");
    printf("pa\n");
}

static void i_h_s_0(int index_a,int index_b)
{
    int i;

    i = 0;
    while (i < index_b - index_a - 1)
    {
        printf("rrb\n");
        i++;
    }
    i = 0;
    while (i < index_a + 1)
    {
        printf("pb\n");
        i++;
    }
}

/// @brief  必要なステップ数 index_b * 2 + 4
/// @param index_a 
/// @param index_b 
void swap_stack_b_0(int index_a,int index_b)
{
    // pass
    h_s_0(index_a,index_b);
    m_h_s_0();
    i_h_s_0(index_a, index_b);
}
#include <stdio.h>


static void h_s_1(int a,int b)
{
    int i;

    i = 0;
    while (i < b + 1)
    {
        printf("rrb\n");
        printf("pa\n");
        i++;
    }
    i = 0;
    while (i < a - b)
    {
        printf("rrb\n");
        i++;
    }
}

static void m_h_s_1()
{
    printf("pb\n");
    printf("rb\n");
    printf("pa\n");
}

static void i_h_s_1(int a,int b)
{
    int i;

    i = 0;
    while (i < a - b - 1)
    {
        printf("rb\n");
        i++;
    }
    i = 0;
    while (i < b + 1)
    {
        printf("pb\n");
        printf("rb\n");
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
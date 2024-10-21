#include "swap.h"
#include "../../src/output/output.h"

static void run_swap(int index_a,int index_b, int stack_b_length, int i)
{
    if (i == 0)
        swap_stack_b_0(index_a,index_b);
    else if (i == 1) 
        swap_stack_b_1(index_a,index_b,stack_b_length);
    else if (i == 2) 
        swap_stack_b_2(index_a,index_b, stack_b_length);
    else if (i == 3)
        swap_stack_b_3(index_a, index_b);
    else
        put_str("idiot\n");
}


#include <stdio.h>
/// @brief  最適なswap方法を選択して実行します.
/// @param index_a 
/// @param index_b 
/// @param stack_b_length 
void oswap(int index_a,int index_b, int stack_b_length)
{
    int a[4] ;
    int i;
    int min;
    int min_index;

    a[0] = index_b * 2 + 4;
    a[1] = 4 * stack_b_length + 2 - 2 * (index_a + index_b);
    a[2] = 2 * (index_a + 1) + 6 * (stack_b_length - index_b);
    a[3] = 3 * index_b - index_a;
    i = 0;
    min = a[i];
    min_index = i;
    while (i <= 3)
    {
        if (a[i] < min)
        {
            min = a[i];
            min_index = i;
        }
        i++;
    }
    // printf("a[0] %d a[1] %d a[2] %d a[3] %d\n",a[0],a[1],a[2],a[3]);
    // printf("                          %d swap used\n",min_index);
    run_swap(index_a, index_b, stack_b_length, min_index);
}


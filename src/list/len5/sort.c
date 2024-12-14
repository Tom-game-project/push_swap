#include "../list.h"
#include "../len3/len3.h"
#include "len5_helper.h"

// for test TODO
#include <stdio.h>

#define LEN5_MAX 5

#define CASE_XXXOO 0b100011
#define CASE_XXOXO 0b100101
#define CASE_XOXXO 0b101001
#define CASE_OXXXO 0b110001
#define CASE_XXOOX 0b100110
#define CASE_XOXOX 0b101010
#define CASE_OXXOX 0b110010
#define CASE_XOOXX 0b101100
#define CASE_OXOXX 0b110100
#define CASE_OOXXX 0b111000

static int ft_pow(int a, int b)
{
	if (b == 1)
		return (a);
	else if (b == 0)
		return (1);
	return (a * ft_pow(a, b - 1));
}

static int find_0_1_map(t_node **a_node)
{
	int i;
	int t;
	int r;

	r = 0;
	i = LEN5_MAX;
	while (0 < i)
	{
		i -= 1;
		t = get_elem(*a_node, i);
		r+=ft_pow(2, LEN5_MAX - 1 - i) * (t == 1 || t == 2); 
	}
	r += 0b100000;
	return (r);
}

static int stash_min(t_node **node_a, t_node **node_b,t_node **ops, int mapped_int)
{
	if (CASE_XXXOO == mapped_int)
		return (case_func_xxxoo(node_a, node_b, ops));
	else if (CASE_XXOXO == mapped_int)
		return (case_func_xxoxo(node_a, node_b, ops));
	else if (CASE_XOXXO == mapped_int)
		return (case_func_xoxxo(node_a, node_b, ops));
	else if (CASE_OXXXO == mapped_int)
		return (case_func_oxxxo(node_a, node_b, ops));
	else if (CASE_XXOOX == mapped_int)
		return (case_func_xxoox(node_a, node_b, ops));
	else if (CASE_XOXOX == mapped_int)
		return (case_func_xoxox(node_a, node_b, ops));
	else if (CASE_OXXOX == mapped_int)
		return (case_func_oxxox(node_a, node_b, ops));
	else if (CASE_XOOXX == mapped_int)
		return (case_func_xooxx(node_a, node_b, ops));
	else if (CASE_OXOXX == mapped_int)
		return (case_func_oxoxx(node_a, node_b, ops));
	else if (CASE_OOXXX == mapped_int)
		return (case_func_ooxxx(node_a, node_b, ops));
	else
		return (0);
}

static int stack_b_proc(t_node **node_b, t_node **ops)
{
	int b0;
	int b1;

	b0 = get_elem(*node_b, 0);
	b1 = get_elem(*node_b, 1);
	if (b0 < b1)
		push(ops, SB);
	push(ops, PA);
	push(ops, PA);
	return (0);
}


int len5_sort(t_node **node_a, t_node **node_b, t_node **ops)
{
	int int_tmp;
	int_tmp = find_0_1_map(node_a);
	printf("find_0_1_map %d \n", int_tmp);
	stash_min(node_a, node_b, ops, int_tmp);
	len3_sort_base(node_a, ops, 3);
	stack_b_proc(node_b, ops);

	printf("node a\n");
	print_list(node_a);
	printf("node b\n");
	print_list(node_b);
	return (0);
}

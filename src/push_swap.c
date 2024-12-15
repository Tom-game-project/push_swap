/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:59:02 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 19:59:17 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "src/list/list.h"
#include "input_checker/input_checker.h"
#include "list/len2/len2.h"
#include "output/output.h"
#include "strnumtools/strnumtools.h"
#include "list/list.h"
#include "list/len3/len3.h"
#include "list/len4/len4.h"
#include "list/len5/len5.h"

#include <stdlib.h>

/// ここで、1から始まる配列にします
int *create_list(int argc ,char *argv[])
{
    int *stack;
    int i;
    int j;
    int c;

    stack = (int *) malloc(sizeof(int) * (argc - 1));
    if (stack == NULL)
	    return (NULL);
    i = 0;
    while (++i < argc)
    {
        j = 0;
        c = 0;
        while (++j < argc)
        {
            if (lt(argv[i],argv[j]))
               c++;
        }
        stack[i - 1] = argc - 1 - c;
    }
    return (stack);
}

/// @brief if something wrong return 1
int set_stack_a(t_node **a,int argc, char *argv[])
{
    int *stack;
    int i;
    int error_flag;

    i = 0;
     error_flag = 0;   
    stack = create_list(argc, argv);
    if (stack == NULL)
	    return (1);
    while (++i < argc)
	    error_flag = push(a,stack[i - 1]);
    free(stack);
    return (error_flag);
}

int my_sort(int (*func[5])(t_node **node_a,t_node **node_b, t_node **ops), t_node **node_a,t_node **node_b, t_node **ops)
{
	int a_len;

	func[0] = len2_sort;
	func[1] = len3_sort;
	func[2] = len4_sort;
	func[3] = len5_sort;
	func[4] = merge_sort;
	a_len = len(*node_a);
	if (a_len == 1)
		return (0);
	else if (2 <= a_len && a_len <= 5)
		return (func[a_len - 2](node_a, node_b, ops));
	else
		return (func[4](node_a, node_b, ops));
}

int main(int argc, char *argv[])
{
    t_node *a;
    t_node *b;
    t_node *ops;
    int (*func[5])(t_node **node_a,t_node **node_b, t_node **ops);

    if (!is_valid_all(argc, argv))
        return print_error();
    a = NULL;
    b = NULL;
    ops = NULL;
    if (set_stack_a(&a, argc, argv))
        return print_error();
    my_sort(func, &a, &b, &ops);
    output_all_ops(&ops);
    clear(&a);
    clear(&b);
    return (0);
}

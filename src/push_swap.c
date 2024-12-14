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
#include "../src/input_checker/input_checker.h"
#include "../src/output/output.h"
#include "../src/strnumtools/strnumtools.h"
#include "../src/list/list.h"
#include <stdlib.h>
#include <stdio.h>

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

int main(int argc, char *argv[])
{
    t_node *a;
    t_node *b;
    t_node *ops;

    if (!is_valid_all(argc, argv))
        return print_error();
    a = NULL;
    b = NULL;
    ops = NULL;
    if (set_stack_a(&a, argc,argv))
        return print_error();
    merge_sort(&a, &b, &ops); 
    output_all_ops(&ops);
    clear(&a);
    return (0);
}


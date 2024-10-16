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

int *create_list(int argc ,char *argv[])
{
    int *stack;
    int i;
    int j;
    int c;

    stack = (int *) malloc(sizeof(int) * (argc - 1));
    i = 1;
    while (i < argc)
    {
        j = 1;
        c = 0;
        while (j < argc)
        {
            if (lt(argv[i],argv[j]))
               c++;
            j++;        
        }
        stack[i - 1] = argc - 1 - c;
        i++;
    }
    return (stack);
}

int main(int argc, char *argv[])
{
    int *stack;
    int i;
    t_node *node;

    // if (!is_valid_all(argc, argv)){
    //     print_error();
    //     return (1);
    // }

    // for (int i = 0; i < argc; i++){
    //     printf("str %s; is valid?%d;\n", argv[i], is_valid_string(argv[i]));
    // }
    stack = create_list(argc, argv);
    
    i = 0;
    node = NULL;
    while (i + 1 < argc)
    {
        // printf("%s %d\n",argv[i+1], stack[i]);
        heappush(&node,stack[i]);
        i++;
    }
    while (len(node) != 0)
        heappop(&node);
    free(stack);
    return (0);
}
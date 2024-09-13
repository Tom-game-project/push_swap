/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:02 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 22:06:27 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/list/list.h"
#include <stdlib.h>
#include "stdio.h"
#include <assert.h>

/// @brief pop test 
/// @return
int	main()
{
	t_node	*node;

	node = NULL;
	for (int i = 0;i < 10; i++){
        push(&node, i);
    }

    t_node* tmp_node = pop_elem(&node);
    while (tmp_node != NULL){
        printf("poped ptr %p\n",tmp_node);
        printf("poped elem %d\n",tmp_node->i32_data);
        free(tmp_node);
        tmp_node = pop_elem(&node);
    }
    printf("length %d\n", len(node));
    // assert(2 == len(node));
    return (0);
}
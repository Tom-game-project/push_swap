/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:08 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 19:51:58 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/list/list.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    t_node* node;
    t_node* rm_node;

    node= NULL;
    push(&node,1);
    push(&node,2);
    push(&node,3);
    push(&node,4);
    rm_node = pop_index_elem(&node, 2);// remove 3
    printf("removed %d\n",rm_node->i32_data);
    free(rm_node);
    print_ptr(&node);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:11 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 19:55:44 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/list/list.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    t_node* node;

    node= NULL;
    push(&node,1);
    push(&node,2);
    push(&node,3);
    push(&node,4);
    set_num(&node,4,100);
    print_ptr(&node);
    return (0);
}
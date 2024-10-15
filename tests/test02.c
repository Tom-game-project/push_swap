/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:06 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 22:06:49 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/list/list.h"
#include <stdlib.h>
#include "stdio.h"
#include <assert.h>

/// @brief heappop test 
/// @return 
int	main()
{
    t_node *node;

    node = NULL;
    // for (int i = 0;i < 10; i++){
    //     heappush(&node, i);
    // }
    heappush(&node,5);
    heappush(&node,2);
    heappush(&node,7);
    heappush(&node,3);
    heappush(&node,1);
    heappush(&node,6);
    heappush(&node,4);

    while (len(node) != 0)
        heappop(&node);
        // printf("poped%d\n",heappop(&node));

    return (0);
}

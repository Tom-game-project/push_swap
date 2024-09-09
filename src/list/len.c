/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:26 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 21:40:42 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int	len(t_node *node_p)
{
	int	i;

	i = 0;
	while (node_p != NULL)
	{
		i++;
		node_p = node_p->back_p;
	}
	return (i);
}

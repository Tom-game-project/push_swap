/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:15 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 21:09:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_node	*get_back(t_node *node_p)
{
	if (node_p == NULL)
		return (node_p);
	while (node_p -> back_p != NULL)
		node_p = node_p->back_p;
	return (node_p);
}

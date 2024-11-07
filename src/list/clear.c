/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:15:09 by tmuranak          #+#    #+#             */
/*   Updated: 2024/11/07 21:22:58 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

/**
 * pub clear
 * @brief free: not required
 *        this function for free sall element of lists
 */
int	clear(t_node **lst)
{
	t_node	*value;

	value = pop_elem(lst);
	while (value != NULL)
	{
		free(value);
		value = pop_elem(lst);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:18:12 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 17:51:14 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	is_sorted(t_node *ra)
{
	int	a_length;
	int	i;

	a_length = len(ra);
	i = 0;
	while (i < a_length - 1)
	{
		if (get_elem(ra, i) < get_elem(ra, i + 1))
			i++;
		else
			return (0);
	}
	return (1);
}

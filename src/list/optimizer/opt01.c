/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:05:23 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 16:57:05 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"
#include "opt01_helper.h"

int	opt_nop(t_node **ops)
{
	int	n;

	n = find_nop(*ops);
	while (n != -1)
	{
		pop(ops, n);
		pop(ops, n);
		n = find_nop(*ops);
	}
	return (0);
}


int	opt_rrr(t_node **ops)
{
	int	n;

	n = shortening_rrr(*ops);
	while (n != -1)
	{
		pop(ops, n);
		pop(ops, n); 
		if (insert(ops, n, RRR))
			return (1);
		n = shortening_rrr(*ops);
	}
	return (0);
}

int	opt_rr(t_node **ops)
{
	int	n;

	n = shortening_rr(*ops);
	while (n != -1)
	{
		pop(ops, n);
		pop(ops, n); 
		if (insert(ops, n, RR))
			return (1);
		n = shortening_rr(*ops);
	}
	return (0);
}

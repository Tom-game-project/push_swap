/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:02:00 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 16:02:02 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "len3_helper.h"

/// {1, 2, 3} is sorted
/// nop
int len3_0_1(t_node **ops)
{
	(void) ops;
	return (0);
}

/// {1, 3, 2}
int len3_0_2(t_node **ops)
{
	if (push(ops, SA))
		return (1);
	if (push(ops, RA))
		return (1);
	return (0);
}

/// {2, 1, 3}
int len3_1_0(t_node **ops)
{
	if (push(ops, SA))
		return (1);
	return (0);
}

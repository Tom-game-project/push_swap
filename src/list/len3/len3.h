/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:02:29 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 17:35:07 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEN3_H
# define LEN3_H

# include "../list.h"

int	len3_sort_base(t_node **node_a, t_node **ops, int base);
int	len3_sort(t_node **node_a, t_node **node_b, t_node **ops);

#endif

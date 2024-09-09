/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:35 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 21:36:21 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_LIST_H
# define PRIVATE_LIST_H
# include "list.h"

// unsafe modules
t_node	*get_raw_ptr(t_node **node_p_p, int index);

#endif
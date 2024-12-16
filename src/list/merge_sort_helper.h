/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_helper.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:59:47 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 17:00:08 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_SORT_HELPER_H
# define MERGE_SORT_HELPER_H

# include "list.h"

int	push_end(t_node **f, t_node**t, char f_f, t_node **ops);
int	push_head(t_node **f, t_node**t, char f_f, t_node **ops);
int	push_second(t_node **f, t_node**t, char f_f, t_node **ops);

#endif

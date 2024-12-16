/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt01_helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:05:15 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 16:56:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT01_HELPER_H
# define OPT01_HELPER_H

# include "../list.h"

int	find_nop(t_node *ops);
int	shortening_rrr(t_node *ops);
int	shortening_rr(t_node *ops);

#endif

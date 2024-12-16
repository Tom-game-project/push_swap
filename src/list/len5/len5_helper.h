/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len5_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:03:42 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/16 16:03:44 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEN5_HELPER_H
#define LEN5_HELPER_H

#include "../list.h"

// helper00.c
int case_func_xxxoo(t_node **node_a, t_node **node_b, t_node **ops);
int case_func_xxoxo(t_node **node_a,t_node **node_b,t_node **ops);
int case_func_xoxxo(t_node **node_a,t_node **node_b,t_node **ops);
int case_func_oxxxo(t_node **node_a,t_node **node_b,t_node **ops);
int case_func_xxoox(t_node **node_a,t_node **node_b,t_node **ops);

// helper01.c
int case_func_xoxox(t_node **node_a, t_node **node_b, t_node **ops);
int case_func_oxxox(t_node **node_a, t_node **node_b, t_node **ops);
int case_func_xooxx(t_node **node_a, t_node **node_b, t_node **ops);
int case_func_oxoxx(t_node **node_a, t_node **node_b, t_node **ops);
int case_func_ooxxx(t_node **node_a, t_node **node_b, t_node **ops);

#endif

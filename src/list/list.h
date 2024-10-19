/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:29 by tmuranak          #+#    #+#             */
/*   Updated: 2024/09/09 21:48:37 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_node	t_node;

typedef struct s_node{
	int		i32_data;
	t_node	*pre_p;
	t_node	*back_p;
}	t_node;

t_node	*init_node(int i32_data);
// t_node	*get_back(t_node *node_p_p);
int		push(t_node **parent_p, int i32_data);
int		insert(t_node **node_p, int index, int value);

// pop
int		pop(t_node **node_p_p, int index);
t_node	*pop_elem(t_node **node_p_p);
t_node	*pop_index_elem(t_node **node_p_p, int index);

// set
void	set_num(t_node **node_p_p, int index, int value);

// heap
int		heappush(t_node **parent_p, int i32_data);
int		heappop(t_node **node_p_p);

// merge sort

void merge_sort(t_node **node_a,t_node **node_b);

// length
int		len(t_node *node_p);

// clear
int clear(t_node **lst);

// test function
void	print_list(t_node	**parent);
void	print_ptr(t_node	**parent);

// unsafe function
// do not try to access out of range
int		get_elem(t_node *node_p, int index);
t_node	*get_ptr(t_node *node_p, int index);

#endif
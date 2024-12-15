#include "list.h"

int	push_end(t_node **f, t_node**t, char f_f, t_node **ops)
{
	if (insert(t, 0, pop(f, len(*f) - 1)))
		return (1);
	if (f_f == 'a')
	{
		if (push(ops, RRA))
			return (1);
		if (push(ops, PB))
			return (1);
	}
	else
	{
		if (push(ops, RRB))
			return (1);
		if (push(ops, PA))
			return (1);
	}
	return (0);
}

int	push_head(t_node **f, t_node**t, char f_f, t_node **ops)
{
	if (insert(t, 0, pop(f, 0)))
		return (1);
	if (f_f == 'a')
	{
		if (push(ops, PB))
			return (1);
	}
	else
	{
		if (push(ops, PA))
			return (1);
	}
	return (0);
}

int	push_second(t_node **f, t_node**t, char f_f, t_node **ops)
{
	if (insert(t, 0, pop(f, 1)))
		return (1);
	if (f_f == 'a')
	{
		if (push(ops, SA))
			return (1);
		if (push(ops, PB))
			return (1);
	}
	else
	{
		if (push(ops, SB))
			return (1);
		if (push(ops, PA))
			return (1);
	}
	return (0);
}

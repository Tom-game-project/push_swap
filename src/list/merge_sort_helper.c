#include "list.h"

void	push_end(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, 0, pop(f, len(*f) - 1));
	if (f_f == 'a')
	{
		push(ops, RRA);
		push(ops, PB);
	}
	else
	{
		push(ops, RRB);
		push(ops, PA);
	}
}

void	push_head(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, 0, pop(f, 0));
	if (f_f == 'a')
		push(ops, PB);
	else
		push(ops, PA);
}

void	push_second(t_node **f, t_node**t, char f_f, t_node **ops)
{
	insert(t, 0, pop(f, 1));
	if (f_f == 'a')
	{
		push(ops, SA);
		push(ops, PB);
	}
	else
	{
		push(ops, SB);
		push(ops, PA);
	}
}


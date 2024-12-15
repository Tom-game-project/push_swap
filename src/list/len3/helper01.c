#include "len3_helper.h"

/// {2, 3, 1}
int len3_1_2(t_node **ops)
{
	if (push(ops, RRA))
		return (1);
	return (0);
}

/// {3, 1, 2}
int len3_2_0(t_node **ops) 
{
	if (push(ops, RA))
		return (1);
	return (0);
}

/// {3, 2, 1}
int len3_2_1(t_node **ops) 
{
	if (push(ops, SA))
		return (1);
	if (push(ops, RRA))
		return (1);
	return (0);
}


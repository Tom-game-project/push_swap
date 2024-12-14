#include "len3_helper.h"

/// {2, 3, 1}
void len3_1_2(t_node **ops)
{
	push(ops, RRA);
}

/// {3, 1, 2}
void len3_2_0(t_node **ops) 
{
	push(ops, RA);
}

/// {3, 2, 1}
void len3_2_1(t_node **ops) 
{
	push(ops, SA);
	push(ops, RRA);
}


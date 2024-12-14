#include "len3_helper.h"

/// {1, 2, 3} is sorted
/// nop
void len3_0_1(t_node **ops)
{
	(void) ops;
}

/// {1, 3, 2}
void len3_0_2(t_node **ops)
{
	push(ops, SA);
	push(ops, RA);
}

/// {2, 1, 3}
void len3_1_0(t_node **ops)
{
	push(ops, SA);
}

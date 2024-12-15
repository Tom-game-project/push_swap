#include "../list.h"

/// rotate
static void len4_case_0(t_node **node_a, t_node **ops)
{
	pop(node_a, 0);
	push(ops, PB);
}

static void len4_case_1(t_node **node_a, t_node **ops)
{
	push(node_a, pop(node_a, 0));
	pop(node_a, 0);
	push(ops, RA);
	push(ops, PB);
}

static void len4_case_2(t_node **node_a, t_node **ops)
{
	push(node_a, pop(node_a, 0));
	push(node_a, pop(node_a, 0));
	pop(node_a, 0);
	push(ops, RA);
	push(ops, RA);
	push(ops, PB);
}

static void len4_case_3(t_node **node_a, t_node **ops)
{
	insert(node_a, 0, pop(node_a, len(*node_a) - 1));
	pop(node_a, 0);
	push(ops, RRA);
	push(ops, PB);
}

void set_func_00(void (*func[4])(t_node **node_a, t_node **ops))
{
	func[0] = len4_case_0;
	func[1] = len4_case_1;
	func[2] = len4_case_2;
	func[3] = len4_case_3;
}


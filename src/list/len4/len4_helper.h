#ifndef LEN4_HELPER_H
#define LEN4_HELPER_H

#include "../list.h"

void len4_case_0(t_node **node_a, t_node **ops);
void len4_case_1(t_node **node_a, t_node **ops);
void len4_case_2(t_node **node_a, t_node **ops);
void len4_case_3(t_node **node_a, t_node **ops);
void set_func_00(void (*func[4])(t_node **node_a, t_node **ops));

#endif


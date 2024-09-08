#include "list.h"
#include <stdlib.h>

int len(t_node *node_p)
{
    int i;

    i = 0;
    while (node_p!=NULL)
    {
        i++;
        node_p = node_p->back_p;
    }
    return (i);
}
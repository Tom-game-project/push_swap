#include "list.h"


int is_sorted(t_node *ra)
{
    int a_length;
    int i;

    a_length = len(ra);
    i = 0;
    while (i < a_length - 1)
    {
        if (get_elem(ra, i) < get_elem(ra, i + 1))
            i++;
        else
            return (0);
    }
    return (1);
}

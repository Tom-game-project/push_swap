#include "list.h"
#include <stdlib.h>

int get_elem(t_node* node_p,int index){
    int i;

    i = 0;
    while (i <= index)
    {
        i += 1;
        if (node_p == NULL)
            return (404); // Error!
        node_p = node_p -> back_p;
    }
    return (node_p -> i32_data);
}

t_node* get_ptr(t_node* node_p,int index){
    int i;

    i = 0;
    while (i < index)
    {
        i += 1;
        if (node_p == NULL)
            return (NULL); // Error!
        node_p = node_p -> back_p;
    }
    return (node_p);
}

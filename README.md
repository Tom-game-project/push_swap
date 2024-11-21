# Push Swap

## Invalid operation -> Error

```c

#include "src/list/list.h"

int main(){
    t_node *node;

    push(&node, 1);
    push(&node, 1);
    push(&node, 1);
    push(&node, 1);

    print_list(&node);
    return (0);
}
```

## how to use 

```
./push_swap 1 3 2 5 4
```

#include "src/list/list.h"
#include <stdlib.h>
#include "stdio.h"
#include <assert.h>

/// @brief pop test 
/// @return 
int main(){
    t_node *node;

    node = NULL;
    // for (int i = 0;i < 10; i++){
    //     heappush(&node, i);
    // }
    heappush(&node,5);
    heappush(&node,2);
    heappush(&node,7);
    heappush(&node,3);
    heappush(&node,1);
    heappush(&node,6);
    heappush(&node,4);

    print_list(&node);
    return (0);
}
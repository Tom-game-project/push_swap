#include "src/list/list.h"
#include <stdlib.h>
#include "stdio.h"
#include <assert.h>

/// @brief
/// @return 
int main(){
    t_node *node;

    // push(&node, 1);
    // print_list(&node);
    node = NULL;
    for (int i = 0;i < 10; i++){
        push(&node, i);
    }

    t_node* tmp_node = pop_elem(&node);
    while (tmp_node != NULL){
        printf("poped ptr %p\n",tmp_node);
        printf("poped elem %d\n",tmp_node->i32_data);
        free(tmp_node);
        tmp_node = pop_elem(&node);
    }
    printf("length %d\n", len(node));
    // assert(2 == len(node));
    return (0);
}
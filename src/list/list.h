#ifndef LIST
#define LIST

typedef struct s_node t_node;

typedef struct s_node{
    int i32_data;
    t_node* pre_p;
    t_node* back_p;
} t_node;


t_node* init_node(int i32_data);
t_node* get_back(t_node* node_p_p);
int push(t_node** parent_p,int i32_data);
void print_list(t_node** parent);

#endif
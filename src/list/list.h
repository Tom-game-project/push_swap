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
int insert(t_node **node_p, int index, int value);
t_node* pop_elem(t_node **node_p_p);
void assignment(t_node** node_p_p,int index, int value);
int heappush(t_node** parent_p,int i32_data);
int len(t_node *node_p);

// test function
void print_list(t_node** parent);
void print_ptr(t_node** parent);

// unsafe function
// do not try to access out of range
int get_elem(t_node* node_p,int index);
t_node* get_ptr(t_node* node_p,int index);

#endif
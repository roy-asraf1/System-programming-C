#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_
{
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_
{
    int node_num;
    pedge edges;
    int index; // for TSP helper
    struct GRAPH_NODE_ *next;

} node, *pnode;

typedef struct queueNode
{
    pnode data;
    int priority;
    struct queueNode *next;
} qnode;

//********* helper for create node and edge *********

pedge create_new_edge(int, pedge,pnode);
pnode create_new_node(int);
pnode new_node(int, pnode); // create a new node
pnode find_node(int, pnode); // find the node in the graph
void del_out(pnode); // delete all outgoing edges
void rem_src(int, pnode); // remove the source node from the outgoing edges
pnode insert_node(int, pnode *); // insert a node into the graph

// ****** algo function *******
void shortest_path_algorithm(int *, pnode); // using Dijkstra's algorithm
void permutation(int *, int, int, int, int *, pnode);  // for TSP
void swap(int *, int *); // for permutation

// ****** command function *******

void build_graph_cmd(pnode *); // build the graph
void insert_node_cmd(pnode *); // insert a node into the graph
void delete_node_cmd(pnode *); // delete a node from the graph
void printGraph_cmd(pnode); // for self debug
void deleteGraph_cmd(pnode *); // delete the graph
void shortsPath_cmd(pnode); // shortest path using Dijkstra's algorithm
void TSP_cmd(pnode); // TSP

// ****** queue function *******

qnode *create_new_queue_node(pnode, int);
pnode pop(qnode **);
void push(qnode **, pnode, int);
int is_empty(qnode **);
int peek(qnode **);

#endif

#include <limits.h>
#include "graph.h"
#include <float.h>
#include <stdio.h>
#include <stdlib.h>


// ------------------ Graph ------------------

void build_graph_cmd(pnode *head)
{
    int input;
    scanf("%d", &input);
    pnode src = find_node(input, *head);
    pedge before = NULL;
    while (scanf("%d", &input) == 1)
    {
        pnode dest = find_node(input, *head);
        scanf("%d", &input);
        before = create_new_edge(input, before, dest);
    }
    src->edges = before;
}

void insert_node_cmd(pnode *head)
{
    int input;
    scanf("%d", &input);
    pnode src = find_node(input, *head);
    if (*head == NULL)
    {
        *head = new_node(input, NULL);
        src = *head;
    }
    else if (src != NULL)
    {
        del_out(src);
    }
    else
    {
        src = insert_node(input, head);
    }
    pedge prev = NULL;
    while (scanf("%d", &input) == 1)
    {
        pnode dest = find_node(input, *head);
        scanf("%d", &input);
        prev = create_new_edge(input, prev, dest);
    }
    src->edges = prev;
}

void delete_node_cmd(pnode *head)
{
    int input;
    scanf("%d", &input);
    pnode c = *head;
    pnode delete = NULL;
    if (c->node_num == input)
    {
        *head = (c->next);
        delete = c;
    }
    else
    {
        while (c->next)
        {
            if (c->next->node_num == input)
            {
                delete = c->next;
                c->next = delete->next;
                break;
            }
            c = c->next;
        }
    }
    c = *head;
    while (c != NULL)
    {
        rem_src(input, c);
        c = c->next;
    }
    del_out(delete);
    free(delete);
}

void printGraph_cmd(pnode head)
{ // for self debug
    while (head != NULL)
    {
        printf("node id: %d\n", head->node_num);
        pedge src = head->edges;
        while (src != NULL)
        {
            printf("%d -> %d   w: %d\n", head->node_num, src->endpoint->node_num, src->weight);
            src = src->next;
        }
        head = head->next;
    }
}

void deleteGraph_cmd(pnode *head)
{
    pnode src = *head;
    while (src != NULL)
    {
        del_out(src);
        pnode delete = src;
        src = src->next;
        free(delete);
    }
}
void shortsPath_cmd(pnode head)
{
    int src, dest;
    int input = 0;
    while (input == 0)
        input = scanf("%d", &src);
    input = 0;
    while (input == 0)
        input = scanf("%d", &dest);
    pnode source;
    pnode curr = head;
    int i = 0;
    int in_d,in_s; // index of dest and src
    while (curr != NULL)
    {
        curr->index = i;
        if (curr->node_num == src)
        {
            source = curr;
            in_s = i;
        }
        if (curr->node_num == dest)
        {
            in_d = i;
        }
        i++;
        curr = curr->next;
    }

    int *arr = (int *)malloc(sizeof(int) * i);
    for (int j = 0; j < i; j++)
        arr[j] = INT_MAX;
    arr[in_s] = 0;
    shortest_path_algorithm(arr, source);
    if (arr[in_d] < INT_MAX)
        printf("Dijsktra shortest path: %d \n", arr[in_d]);
    else
        printf("Dijsktra shortest path: -1 \n");
    free(arr);
}

void TSP_cmd(pnode head)
{
    int input;
    int nodes_number = 0;
    scanf("%d", &input);
    int *arr = (int *)malloc(sizeof(int) * input);
    for (int i = 0; i < input; i++)
        scanf("%d", &arr[i]);

    pnode src = head;
    while (src != NULL)
    {
        src->index = nodes_number;
        nodes_number++;
        src = src->next;
    }
    int help = INT_MAX;
    permutation(arr, 0, input - 1, nodes_number, &help, head);
    if (help != INT_MAX)
        printf("TSP shortest path: %d \n", help);
    else
        printf("TSP shortest path: -1 \n");
    free(arr);
}
// --------------------------------- node and edge  ---------------------------------
pedge create_new_edge(int weight, pedge next, pnode dis)
{
    pedge e = (pedge)malloc(sizeof(edge));
    e->endpoint = dis;
    e->next = next;
    e->weight = weight;
    return e;
}
pnode new_node(int key, pnode next)
{
    pnode pn = (pnode)malloc(sizeof(node));
    pn->node_num = key;
    pn->next = next;
    pn->edges = NULL;
    return pn;
}

pnode find_node(int d, pnode head)
{
    while (head != NULL)
    {
        if (head->node_num == d)
            return head;

        head = head->next;
    }
    return NULL;
}

pnode create_new_node(int len)
{
    pnode head = NULL;
    for (int i = len- 1; i >= 0; i--)
        head = new_node(i, head);

    return head;
}

void del_out(pnode source)
{
    pedge next = source->edges;
    while (next)
    {
        pedge prev = next;
        next = next->next;
        free(prev);
    }
}

void rem_src(int data, pnode source)
{
    pedge e = source->edges;
    if (e != NULL)
    {
        if (e->endpoint->node_num == data)
        {
            pedge delete = e;
            source->edges = e->next;
            free(delete);
            return;
        }
        while (e->next != NULL)
        {
            if (e->next->endpoint->node_num == data)
            {
                pedge delete = e->next;
                e->next = delete->next;
                free(delete);
                return;
            }
            e = e->next;
        }
    }
}

pnode insert_node(int data, pnode *head)
{
    pnode *p = head;
    while ((*p)->next)
    {
        if ((*p)->node_num < data && (*p)->next->node_num > data)
        {
            pnode newNode= new_node(data, (*p)->next);
            (*p)->next = newNode;
            return newNode;
        }
        p = &((*p)->next);
    }
    pnode newNode = new_node(data, (*p)->next);
    (*p)->next = newNode;
    return newNode;
}
// --------------------------------- algo ---------------------------------
void shortest_path_algorithm(int *arr, pnode src)
{
    qnode *queue_src = create_new_queue_node(src, 0);
    while (!is_empty(&queue_src))
    {
        src = pop(&queue_src);
        pedge curr = src->edges;
        while (curr != NULL) // for each edge
        {
            if (arr[src->index] + curr->weight < arr[curr->endpoint->index])
            {
                arr[curr->endpoint->index] = arr[src->index] + curr->weight;
                push(&queue_src, curr->endpoint, arr[curr->endpoint->index]);
            }
            curr = curr->next; // next edge
        }
    }
}

void permutation(int *arr, int start, int end, int nodes_num, int *ans, pnode head)
{
    if (start == end)
    {
        int path = 0;
        int *a = (int *)malloc(sizeof(int) * nodes_num);
        for (int i = 0; i < nodes_num; i++)
            a[i] = INT_MAX;
        pnode src = find_node(arr[0], head);
        a[src->index] = 0;
        for (int i = 1; i <= end; i++)
        {
            shortest_path_algorithm(a, src);
            if (a[find_node(arr[i], head)->index] == INT_MAX)
            {
                free(a);
                return;
            }
            src = find_node(arr[i], head);
            path = path + a[src->index];
            for (int j = 0; j < nodes_num; j++)
                a[j] = INT_MAX;

            a[src->index] = 0;
        }
        free(a);
        if (path < *ans && path != 0)
            *ans = path;
        return;
    }

    for (int k = start; k <= end; k++)
    {
        swap(arr + k, arr + start);
        permutation(arr, start + 1, end, nodes_num, ans, head);
        swap(arr + k, arr + start);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// --------------------------------- queue ---------------------------------

qnode *create_new_queue_node(pnode d, int p)
{
    qnode *temp = (qnode *)malloc(sizeof(qnode));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

int is_empty(qnode **head)
{
    return (*head) == NULL;
}

pnode pop(qnode **head)
{
    pnode temp = (*head)->data;
    qnode *out = *head;
    (*head) = (*head)->next;
    free(out);
    return temp;
}

void push(qnode **head, pnode d, int p)
{
    qnode *start = (*head);
    qnode *temp = create_new_queue_node(d, p);
    if (is_empty(head))
    {
        (*head) = temp;
        return;
    }
    if ((*head)->priority > p)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        while (start->next != NULL && start->next->priority < p)
            start = start->next;

        temp->next = start->next;
        start->next = temp;
    }
}


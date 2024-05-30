#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char action;
    int len;
    pnode head = NULL;
    while (scanf("%c", &action) != EOF)
    {
        switch (action)
        {
        case 'A':
            deleteGraph_cmd(&head);
            scanf("%d", &len);
            head = create_new_node(len);
            break;
        case 'n':
            build_graph_cmd(&head);
            break;
        case 'B':
            insert_node_cmd(&head);
            break;
        case 'p':
            printGraph_cmd(head);
            break;
        case 'S':
            shortsPath_cmd(head);
            break;
        case 'D':
            delete_node_cmd(&head);
            break;
        case 'T':
            TSP_cmd(head);
            break;
        }
    }
    deleteGraph_cmd(&head);
    return 0;
}

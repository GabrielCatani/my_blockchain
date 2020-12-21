#include "../includes/my_blockchain.h"

node *new_node(int nid)
{
    node *element;
    
    element = (node *)malloc(sizeof(node));
    element->nid = nid;
    element->qty_blocks = 0;
    element->blocks = NULL;
    element->next = NULL;

    return element;
}
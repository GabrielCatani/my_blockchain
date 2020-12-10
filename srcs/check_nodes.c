#include "../includes/my_blockchain.h"

node  *check_nodes(node *head, int nid)
{
    node *ptr = NULL;

    if (!head)
        return NULL;
    ptr = head;
    while (ptr)
    {
        if (nid == ptr->nid)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}
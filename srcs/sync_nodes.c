#include "../includes/my_blockchain.h"

void  sync_node(node **head, block *tracked)
{
    block *b_ptr = NULL;
    node *n_ptr = NULL;
    int b_present = 0;

    b_ptr = (*head)->blocks;
    n_ptr = *head;
    while (tracked)
    {
        b_ptr = (*head)->blocks;
        b_present = 0;
        while (b_ptr)
        {
            if ((my_strcmp(b_ptr->bid, tracked->bid)) == 0)
            {
                b_present = 1;
                break;
            }
            b_ptr = b_ptr->next;
        }
        if (!b_present)
        {
            append_block(&n_ptr->blocks, new_block(tracked->bid));
            (*head)->qty_blocks++;
        }
        tracked = tracked->next;
    }


} 

void  sync_nodes(node **head, block *tracked)
{
    node *n_ptr = NULL;

    n_ptr = *head;
    while (n_ptr)
    {
        sync_node(&n_ptr, tracked);
        n_ptr = n_ptr->next;
    }
}
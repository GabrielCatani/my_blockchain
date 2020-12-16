#include "../includes/my_blockchain.h"

void  append_block_in_node(node **head, block *n_block, int nid)
{
    node *n_ptr = NULL;

    n_ptr = *head;
    while (n_ptr)
    {
        if (n_ptr->nid == nid)
        {
            append_block(&n_ptr->blocks, n_block);
            n_ptr->qty_blocks++;
            break;
        }
        
        n_ptr = n_ptr->next;
    }
}
#include "../includes/my_blockchain.h"

void  append_block_in_node(node **head, block *n_block, int nid)
{
    node *n_ptr = NULL;
    block *b_ptr = NULL;

    n_ptr = *head;
    while (n_ptr)
    {
        b_ptr = n_ptr->blocks;
        if (n_ptr->nid == nid)
        {
            append_block(&b_ptr, n_block);
        }
        b_ptr = NULL;
        
        n_ptr = n_ptr->next;
    }
}
#include "../includes/my_blockchain.h"

void  append_block_in_all_nodes(node **head, block *n_block)
{
    node *n_ptr = NULL;
    block *b_ptr = NULL;

    n_ptr = *head;
    while (n_ptr)
    {
        b_ptr = n_ptr->blocks;
        append_block(&b_ptr, n_block);
        n_ptr->qty_blocks++;
        b_ptr = NULL;
        n_ptr = n_ptr->next;
    }
}
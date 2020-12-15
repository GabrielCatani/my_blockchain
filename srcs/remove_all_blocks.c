#include "../includes/my_blockchain.h"

void  remove_all_blocks(node **n_ptr)
{
    block *b_ptr = NULL;
    block *tmp = NULL;

    b_ptr = (*n_ptr)->blocks;
    if (!b_ptr)
        return;

    while (b_ptr)
    {
        tmp = b_ptr;
        b_ptr = b_ptr->next;
        free(tmp->bid);
        tmp->bid = NULL;
        free(tmp);
        tmp = NULL;
    }
}
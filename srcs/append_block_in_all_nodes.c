#include "../includes/my_blockchain.h"

void  append_block_in_all_nodes(node **head, char *bid)
{
    node *n_ptr = NULL;

    n_ptr = *head;
    while (n_ptr)
    {
        append_block(&n_ptr->blocks, new_block(bid));
        n_ptr = n_ptr->next;
    }
}
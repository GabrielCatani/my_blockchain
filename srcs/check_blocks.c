#include "../includes/my_blockchain.h"

int  check_blocks(node *head, char *bid)
{
    node *n_ptr = NULL;
    block *b_ptr = NULL;

    if (!head)
        return 0;

    n_ptr = head;
    while (n_ptr)
    {
        b_ptr = n_ptr->blocks;
        while (b_ptr)
        {
            if (!my_strcmp(bid, b_ptr->bid))
                return 1;
            b_ptr = b_ptr->next;
        }
        n_ptr = n_ptr->next;
    }

    return 0;
}
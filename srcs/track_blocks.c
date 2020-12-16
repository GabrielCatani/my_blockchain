#include "../includes/my_blockchain.h"

int block_tracked(block *tracker, char *bid)
{
    if (!tracker)
        return 0;
    while (tracker)
    {
        if ((my_strcmp(tracker->bid, bid)) == 0)
            return 1;
        tracker = tracker->next;
    }

    return 0;
}

block *track_blocks(node *head)
{
    node *n_ptr = NULL;
    block *tracker = NULL;
    block *b_ptr = NULL;
    n_ptr = head;

    if (!n_ptr)
        return NULL;
    while (n_ptr)
    {
        b_ptr = n_ptr->blocks;
        while (b_ptr)
        {
            if (!block_tracked(tracker, b_ptr->bid))
            {
                append_block(&tracker, b_ptr);
            }
            b_ptr = b_ptr->next;
        }
        n_ptr = n_ptr->next;
    }

    return tracker;
}
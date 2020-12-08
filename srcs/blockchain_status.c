#include "../includes/my_blockchain.h"

int check_block_qty(node *head)
{
    node *ptr = NULL;
    node *ref = NULL;
    int sync = 1;
    
    ptr = head;
    ref = head;
    while (ref)
    {
        ptr = ref->next;
        while (ptr)
        {
            if (ptr->qty_blocks != ref->qty_blocks)     
                sync = 0;
            ptr = ptr->next;
        }
        ref = ref->next;
        ptr = ref;
    }

    return sync;
}

int check_block_sync(node *start)
{
    block *b_ref = NULL;
    node *n_ptr = NULL;
    int counter = 0;
    int block_index = 0;

    if (start->next == NULL)
        return 0;

    b_ref = start->blocks;
    n_ptr = start->next;
    while (b_ref)
    {
        counter = 0;
        while (counter < block_index)
        {
            n_ptr->blocks = n_ptr->blocks->next;
            counter++;
        }
        printf("%s - %s\n", b_ref->bid, n_ptr->blocks->bid);
        if (my_strcmp(b_ref->bid, n_ptr->blocks->bid) != 0)
            return 0;
        b_ref = b_ref->next;
        block_index++;
    }
    return 1;
}

void blockchain_status(node *head)
{
    int sync = 0;
    //int nbr_nodes = 0;

    sync = check_block_qty(head);
    printf("%d\n", sync);
    sync = check_block_sync(head);
    printf("%d\n", sync);


}
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

int check_block(node *head)
{
    int sync = 1;
    node *ptr;
    node *ref;

    ptr = head;
    ref = head;
    while (ref)
    {
        ptr = ref->next;
        while (ptr)
        {
            while (ref->blocks)
            {
                while (ptr->blocks)
                {
                    if (my_strcmp(ref->blocks->bid, ptr->blocks->bid))
                    {
                        sync = 0;
                        break;
                    }
                    ptr->blocks = ptr->blocks->next;
                }
                if (sync == 1)
                    return sync;
                ref->blocks = ref->blocks->next;
            }
            ptr = ptr->next;
        }
        ref = ref->next;
        ptr = ref;
    }

    return sync;
}

void blockchain_status(node *head)
{
    //int nbr_nodes = 0;
    int sync = 0;

    sync = check_block_qty(head);
    printf("%d\n", sync);
    sync = check_block(head);
    printf("%d\n", sync);
    //nodes_qty();


}
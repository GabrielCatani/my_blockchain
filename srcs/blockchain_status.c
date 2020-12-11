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
    int nbr_blocks = 0;
    int count = 0;
    block *base_ptr = NULL;
    node *ptr_node = NULL;
    block *compare_ptr = NULL;

    base_ptr = start->blocks;
    ptr_node = start->next;
    compare_ptr = ptr_node->blocks;
    while (base_ptr)
    {
        while (ptr_node)
        {
            count = 0;
            compare_ptr = ptr_node->blocks;
            while (count < nbr_blocks)
            {
                compare_ptr = compare_ptr->next;
                count++;
            }
            if (my_strcmp(base_ptr->bid, compare_ptr->bid) != 0)
                return 0;
            
            ptr_node = ptr_node->next;
        }
        base_ptr = base_ptr->next;
        nbr_blocks++;
        ptr_node = start->next;
    }

    return 1;
}

void blockchain_status(node *head)
{
    int nbr_nodes = 0;
    node *ptr = head;
    
    if (!head)
    {
        print_prompt(0, nbr_nodes);
        return;
    }
    
    while (ptr)
    {
        nbr_nodes++;
        ptr = ptr->next;
    }
    
    if (check_block_qty(head))
    {
        if (check_block_sync(head))
        {
            print_prompt(1, nbr_nodes);
            return;
        }
    }

    print_prompt(0, nbr_nodes);
}
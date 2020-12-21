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
    block *ref_ptr = NULL;
    node *comp_node_ptr = NULL;
    block *comp_block_ptr = NULL;
    int block_position = 0;
    int count = 0;

    if (!start)
        return 1;
    else if (!start->next)
        return 1;

    if (start)
    {
        ref_ptr = start->blocks;
        if (start->next)
            comp_node_ptr = start->next;
        else
            return 1;
    }

    while (ref_ptr)
    {
        count = 0;
        comp_node_ptr = start->next;
        while (comp_node_ptr)
        {
            comp_block_ptr = comp_node_ptr->blocks;
            while (count < block_position)
            {
                comp_block_ptr = comp_block_ptr->next;
                count++;
            }
            if (ref_ptr && comp_block_ptr && my_strcmp(ref_ptr->bid, comp_block_ptr->bid) != 0)
            {
                return 0;
            }
            comp_node_ptr = comp_node_ptr->next;
        }
        block_position++;
        ref_ptr = ref_ptr->next;
    }

    return 1;
}

void blockchain_status(node *head)
{
    int nbr_nodes = 0;
    node *ptr = head;
    
    if (!head)
    {
        print_prompt(1, nbr_nodes);
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
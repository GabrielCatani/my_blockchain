#include "../includes/my_blockchain.h"

void  remove_block(node **head, char *bid)
{
    node *n_ptr = NULL;
    block *b_ptr = NULL;
    block *tmp = NULL;

    n_ptr = *head;
    while (n_ptr)
    {
        b_ptr = n_ptr->blocks;
        if (b_ptr)
        {
            if (my_strcmp(b_ptr->bid, bid) == 0)
            {
                tmp = b_ptr;
                n_ptr->blocks = b_ptr->next;
                free(tmp);
                tmp = NULL;
                n_ptr->qty_blocks--;
            }
            else
            {
                while (b_ptr)
                {
                    if (b_ptr->next)
                    {
                        if (my_strcmp(b_ptr->next->bid, bid) == 0)
                        {
                            tmp = b_ptr->next;
                            b_ptr->next = b_ptr->next->next;
                            free(tmp);
                            tmp = NULL;
                            n_ptr->qty_blocks--;
                            break;
                        }
                    }
                    b_ptr = b_ptr->next;
                }
            }
        }
        n_ptr = n_ptr->next;
    }
}
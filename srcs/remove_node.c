#include "../includes/my_blockchain.h"

void  remove_node(node **head, int nid)
{
    node *n_ptr = NULL;
    node *tmp = NULL;

    n_ptr = *head;
    if (!n_ptr)
        return;
    if (n_ptr->nid == nid)
    {
        *head = (*head)->next;
        remove_all_blocks(&n_ptr);
        free(n_ptr);
        n_ptr = NULL;
    }
    else
    {
        while (n_ptr)
        {
            if (n_ptr->next && n_ptr->next->nid == nid)
            {
                tmp = n_ptr->next;
                n_ptr->next = tmp->next;
                remove_all_blocks(&tmp);
                tmp = NULL;
                break;
            }
            n_ptr = n_ptr->next;
        }
    }
}
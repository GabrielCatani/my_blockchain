#include "../includes/my_blockchain.h"

void  clear_tracker(block **head)
{
    block *tmp = NULL;
    if (!(*head))
        return;

    while (*head)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp->bid);
        tmp->bid = NULL;
        free(tmp);
        tmp = NULL;
    }
    free((*head));
    *head = NULL;
}
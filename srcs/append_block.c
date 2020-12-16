#include "../includes/my_blockchain.h"

void append_block(block **head, block *n_block)
{
    block *current = *head;

    if (!*head)
    {
        *head = n_block;
    }
    else
    {
        current = *head;
        while (current->next)
            current = current->next;
        current->next = n_block;
    }
}
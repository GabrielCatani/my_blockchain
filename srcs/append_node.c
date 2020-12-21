#include "../includes/my_blockchain.h"

void append_node(node **head, node *n_node)
{
    node *current = *head;

    if (!*head)
    {
        *head = n_node;
    }
    else
    {
        current = *head;
        while (current->next)
            current = current->next;
        current->next = n_node;
    }
}
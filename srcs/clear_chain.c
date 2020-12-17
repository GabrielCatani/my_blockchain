#include "../includes/my_blockchain.h"

void  clear_chain(node **head)
{    
    remove_all_nodes(head);
    free(*head);
    *head = NULL;
}
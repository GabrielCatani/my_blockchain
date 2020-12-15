#include "../includes/my_blockchain.h"

void  remove_all_nodes(node **n_ptr)
{
    while (*n_ptr)
    {
        remove_node(n_ptr, (*n_ptr)->nid);
    }
}
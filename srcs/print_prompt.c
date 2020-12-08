#include "../includes/my_blockchain.h"

void  print_prompt(int sync, int nbr_nodes)
{
    if (sync)
        write(1, "[s", 2);
    else
        write(1, "[-", 2);
    
    my_putnbr(nbr_nodes);
    write(1, "] >", 3);
}
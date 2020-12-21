#include "../includes/my_blockchain.h"

block *new_block(char *bid)
{
    block *element;

    element = (block *)malloc(sizeof(block));
    element->bid = (char *)malloc(sizeof(char) * my_strlen(bid) + 1);
    my_strncpy(element->bid, bid, my_strlen(bid));
    element->bid[my_strlen(bid)] = '\0';

    element->next = NULL;
    return element;
}
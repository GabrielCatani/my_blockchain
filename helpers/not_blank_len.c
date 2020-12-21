#include "../includes/my_blockchain.h"

int not_blank_len(char *word)
{
    int i = 0;

    while (word[i] >= 33)
        i++;
    
    return i;
}
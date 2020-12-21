#include "../includes/my_blockchain.h"

int index_next_word(char *str)
{
    int i = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    
    return i;
}
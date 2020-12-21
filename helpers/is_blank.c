#include "../includes/my_blockchain.h"

int is_blank(char c)
{
    if (c >= 9 && c <= 13)
        return 1;
    
    return 0;
}
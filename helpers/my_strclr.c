#include "../includes/my_blockchain.h"

void my_strclr(char **str)
{
    if (str != NULL && *str != NULL)
    {
        free(*str);
        *str = NULL;
    }
}
#include "../includes/my_blockchain.h"
 
char *my_strchr(char *str, char c)
{
    int len = 0;
    char *ptr = str;

    len = my_strlen(str) + 1;
    while(len--)
    {
        if (*ptr == c)
            return ptr;
        ptr++;
    }

    return NULL;
}
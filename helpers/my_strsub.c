#include "../includes/my_blockchain.h"

char *my_strsub(char *str, int start, int len)
{
    char *ptr;
    int i;

    ptr = (char *)malloc(sizeof(char) * (len + 1));
    if (!ptr || !str)
        return NULL;

    str = str + start;
    i = 0;
    while (i < len)
    {
        ptr[i] = str[i];
        i++;
    }

    ptr[i] = '\0';
    return ptr;
}

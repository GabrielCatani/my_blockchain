#include "../includes/my_blockchain.h"

char *my_strncpy(char *dst, char *src, size_t len)
{
    int i = -1;

    while (src[++i] != '\0' && len > 0)
    {
        dst[i] = src[i];
        len--;
    }

    while (len-- > 0)
    {
        dst[i] = '\0';
        i++;
    }
    return dst;
}
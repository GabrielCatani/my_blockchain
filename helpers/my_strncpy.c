#include "../includes/my_blockchain.h"

char *my_strncpy(char *dst, char *src, size_t len)
{
    size_t i = 0;

    while (src[i] != '\0' && len > i)
    {
        dst[i] = src[i];
        i++;
    }

    while (i < len)
    {
        dst[i] = '\0';
        i++;
    }
    return dst;
}
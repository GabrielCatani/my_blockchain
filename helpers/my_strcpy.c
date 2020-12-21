#include "../includes/my_blockchain.h"

char *my_strcpy(char *dst, char *src)
{
    int i = -1;

    while (src[++i] != '\0')
        dst[i] = src[i];

    dst[i] = '\0';
    return dst;
}
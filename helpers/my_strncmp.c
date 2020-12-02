#include "../includes/my_blockchain.h"

int my_strncmp(char *s1, char *s2, size_t len)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        if (len == 1)
            break;
        s1++;
        s2++;
        len--;
    }
    return (*s1 - *s2);
}
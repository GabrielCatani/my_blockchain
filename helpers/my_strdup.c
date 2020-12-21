#include "../includes/my_blockchain.h"

char *my_strdup(char *str)
{
    char *cpy_str = NULL;
    int index = 0;

    cpy_str = (char *)malloc((my_strlen(str) + 1) * sizeof(char));
    if (!cpy_str || !str)
        return NULL;
    
    while (str[index] != '\0')
    {
        cpy_str[index] = str[index];
        index++;
    }

    cpy_str[index] = '\0';

    return cpy_str;
}
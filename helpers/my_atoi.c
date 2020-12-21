#include "../includes/my_blockchain.h"

int my_atoi(char *s)
{
    int result = 0;
    int index = 0;
    int sign = 1;

    while ((s[index] >= 9  && s[index] <= 13) || s[index] == ' ')
        index++;

    if (s[index] == '-')
        sign = -1;

    while (s[index] >= 48 && s[index] <= 57)
    {
        result = (result * 10) + (s[index] - 48);
        index++;
    }

    return (result * sign);
}
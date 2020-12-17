#include "../includes/my_blockchain.h"

int  how_many_digits(int nbr)
{
    int digits = 0;
    while (nbr > 0)
    {
        nbr /= 10;
        digits++;
    }

    return digits;
}
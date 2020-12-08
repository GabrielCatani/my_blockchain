#include "../includes/my_blockchain.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void  my_putnbr(int nbr)
{
    
    if (nbr < 0)
    {
        my_putchar('-');
        nbr *= -1;
    }

    if (nbr >= 0 && nbr <= 9)
        my_putchar(nbr + 48);
    else
    {
        my_putnbr(nbr / 10);
        my_putchar((nbr % 10) + 48);
    }
}
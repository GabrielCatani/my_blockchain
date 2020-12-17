#include "../includes/my_blockchain.h"

void my_putchar_fd(char c, int fd, int digits)
{
    write(fd, &c, digits);
}

void  my_itoa(int nbr, int fd, int digits)
{
    
    if (nbr < 0)
    {
        my_putchar_fd('-', fd, digits);
        nbr *= -1;
    }

    if (nbr >= 0 && nbr <= 9)
        my_putchar_fd(nbr + 48, fd, digits);
    else
    {
        my_putnbr(nbr / 10);
        my_putchar_fd((nbr % 10) + 48, fd, digits);
    }
}
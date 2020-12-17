#include "../includes/my_blockchain.h"

void  save_blockchain(node *head)
{
    int fd = 0;
    node *n_ptr = NULL;
    block *b_ptr = NULL;

    n_ptr = head;
    if ((fd = open("test/ledger_test_save", O_WRONLY | O_APPEND | O_CREAT, 0666)))
    {
        while (n_ptr)
        {
            my_itoa(n_ptr->nid, fd, how_many_digits(n_ptr->nid));
            write(fd, ":", 1);
            if (n_ptr->blocks)
            {
                b_ptr = n_ptr->blocks;
                while (b_ptr)
                {
                    write(fd, b_ptr->bid, my_strlen(b_ptr->bid));
                    write(fd, ",", 1);
                    b_ptr = b_ptr->next;
                }
            }
            write(fd, "\n", 1);
            n_ptr = n_ptr->next;
        }
        close(fd);  
    }
}
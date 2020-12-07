#include "includes/my_blockchain.h"

int main()
{
    char buf[255];
    int b_read = 0;
    int index = 0;
    int fd = 0;
    node *start = NULL;

    if ((fd = open("test/ledger_test", O_RDONLY)))
    {
        start = load_ledger(fd);
        blockchain_status(start);
        close(fd);
    }


    while (1)
    {
        //blockchain_status();
        index = 0;
        b_read = read(0, buf, 255);
        buf[b_read] = '\0';
        while (buf[index] >= 65 && buf[index] <= 122)
            index++;

        if (!(my_strncmp(buf, "quit", 4)))
            break;
        /*
        else if (!(my_strcmp(command, "ls")))
            check_and_list(flag_option);
        else if (!(my_strcmp(command, "sync")))
            sync_nodes();
        */
        else if (!(my_strncmp(buf, "add", 3)))
            check_and_add(&buf[3]);
        else if (!(my_strncmp(buf, "rm", 2)))
            check_and_rm(&buf[2]);
    }
    
    
    return 0;
}
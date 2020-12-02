#include "../includes/my_blockchain.h"

int main()
{
    char buf[255];
    int b_read = 0;
    char *command = NULL;
    int index = 0;

    while (1)
    {
        //blockchain_status();
        index = 0;
        b_read = read(0, buf, 255);
        buf[b_read] = '\0';
        while (buf[index] >= 65 && buf[index] <= 122)
            index++;
        
        command = (char*)malloc(sizeof(char) * index -1);
        command = my_strncpy(command, buf, index);
        if (!(my_strcmp(command, "quit")))
            break;
        /*
        else if (!(my_strcmp(command, "ls")))
            check_and_list(flag_option);
        else if (!(my_strcmp(command, "sync")))
            sync_nodes();
        */
        else if (!(my_strcmp(command, "add")))
            check_and_add(&buf[my_strlen(command)]);
        else if (!(my_strcmp(command, "rm")))
            check_and_rm(&buf[my_strlen(command)]);
    }

    return 0;
}
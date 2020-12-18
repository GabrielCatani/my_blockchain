#include "../includes/my_blockchain.h"

node *load_ledger(int fd)
{
    char *line = NULL;
    char *bid = NULL;
    char *full_line = NULL;
    node *start = NULL;
    node *n_node = NULL;
    block *n_block = NULL;
    int len = 0;
    
    while ((full_line = my_readline(fd)) != NULL)
    {
        if (my_strncmp(full_line, "EMPTY", 5) == 0)
            break;
        n_node = new_node(my_atoi(full_line));
        
        line = my_strchr(full_line, ':');
        len = 0;
        n_node->qty_blocks = 0;
        append_node(&start, n_node);
        while (*line != '\0')
        {
            if (is_blank(*line++))
                break;
            
            len = my_strchr(line, ',') - line;
            if (len <= 0)
                break;
            bid = (char *)malloc(sizeof(char) * len + 1);
            my_strncpy(bid, line, len);
            bid[len] = '\0';

            n_block = new_block(bid);
            n_node->qty_blocks++;
            append_block(&n_node->blocks, n_block);
            free(bid);
            bid = NULL;
            line += len;
        }
        
        n_node = NULL;
        line = NULL;
        free(full_line);
        full_line = NULL;
    }
    free(full_line);
    full_line = NULL;
    return start;
}
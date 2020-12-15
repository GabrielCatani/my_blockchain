#include "../includes/my_blockchain.h"

node *load_ledger(int fd)
{
    char *line = NULL;
    char *bid = NULL;
    node *start = NULL;
    node *n_node = NULL;
    block *n_block = NULL;
    int len = 0;
    
    while ((line = my_readline(fd)) != NULL)
    {
        n_node = new_node(my_atoi(line));
        
        line = my_strchr(line, ':');
        len = 0;
        n_node->qty_blocks = 0;
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
        append_node(&start, n_node);
    }
    return start;
}
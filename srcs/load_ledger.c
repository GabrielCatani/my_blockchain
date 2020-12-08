#include "../includes/my_blockchain.h"


node *new_node(char *line)
{
    node *element;
    
    element = (node *)malloc(sizeof(node));
    element->nid = my_atoi(line);
    element->qty_blocks = 0;
    element->blocks = NULL;
    element->next = NULL;

    return element;
}

block *new_block(char *bid)
{
    block *element;

    element = (block *)malloc(sizeof(block));
    element->bid = (char *)malloc(sizeof(char) * my_strlen(bid) + 1);
    my_strncpy(element->bid, bid, my_strlen(bid));
    element->bid[my_strlen(bid)] = '\0';

    element->next = NULL;
    return element;
}

void append_node(node **head, node *n_node)
{
    node *current = *head;

    if (!*head)
    {
        *head = n_node;
    }
    else
    {
        current = *head;
        while (current->next)
            current = current->next;
        current->next = n_node;
    }

}

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
        n_node = new_node(line);
        
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
    /*
    while (start)
    {
        printf("%d: ", start->nid);
        while (start->blocks)
        {
            printf("%s, ", start->blocks->bid);
            start->blocks = start->blocks->next;
        }
        printf("\n");
        start = start->next;
    }
    */
    return start;
}
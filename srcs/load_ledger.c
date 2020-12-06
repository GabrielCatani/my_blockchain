#include "../includes/my_blockchain.h"

node *new_node(char *line)
{
    node *element;
    int len = 0;
    element = (node *)malloc(sizeof(node));
    element->nid = my_atoi(line);
    element->blocks = (block *)malloc(sizeof(block));
    while (*line != ':')
        line++;
    line++;
    while (line[len] != ',')
        len++;
    element->blocks->bid = (char *)malloc(sizeof(char) * len + 1);
    my_strncpy(element->blocks->bid, line, len);
    element->blocks->bid[len] = '\0';
    element->blocks->next = NULL;
    element->next = NULL;

    return element;
}

void append_node(node **head, char *data)
{
    node *ref;
    
    ref = *head;
    if (ref)
    {
        while (ref)
            ref = ref->next;
    }

    ref = new_node(data);
}

node *load_ledger(int fd)
{
    char *line = NULL;
    node *start = NULL;
    
    while ((line = my_readline(fd)) != NULL)
    {
        append_node(&start, line);
        printf("%p\n", start);
        
        free(line);
        line = NULL;
    }

    return NULL;
}
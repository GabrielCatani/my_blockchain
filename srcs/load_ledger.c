#include "../includes/my_blockchain.h"

node *new_node(char *line)
{
    node *element;
    
    element = (node *)malloc(sizeof(node));
    element->nid = my_atoi(line);
    element->blocks = NULL;
    element->next = NULL;

    return element;
}

void append_node(node **head, char *data)
{
    node *current = *head;

    if (!*head)
    {
        *head = new_node(data);
    }
    else
    {
        current = *head;
        while (current->next)
            current = current->next;
        current->next = new_node(data);
    }

}

node *load_ledger(int fd)
{
    char *line = NULL;
    node *start = NULL;
    
    while ((line = my_readline(fd)) != NULL)
    {
        append_node(&start, line);
        
        free(line);
        line = NULL;
    }

    while (start)
    {
        printf("%d\n", start->nid);
        start = start->next;
    }

    return NULL;
}
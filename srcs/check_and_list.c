#include "../includes/my_blockchain.h"

void  check_and_list(char *input, node **head)
{
    node *n_ptr = NULL;
    block *b_ptr = NULL;
    int index = 0;
    int len = 0;
    int flag = 0;

    index = index_next_word(input);
	len = not_blank_len(&input[index]);
    
    if (len == 2)
    {
        if (input[2] == 'l')
            flag = 1;
    }

    n_ptr = *head;
    if (n_ptr)
    {
        while (n_ptr)
        {
            printf("%d:", n_ptr->nid);
            b_ptr = n_ptr->blocks;
            if (flag)
            {
                while (b_ptr)
                {
                    printf(" %s,", b_ptr->bid);
                    b_ptr = b_ptr->next;
                }
            }
            n_ptr = n_ptr->next;
            
            printf("\n");
        }
    }
}
#include "../includes/my_blockchain.h"

void check_and_add(char *input, node **head)
{
	int nid = 0;
	char *bid = NULL;
	int index = 0;
	int len = 0;
    node *n_ptr = NULL;

	index = index_next_word(input);
	len = not_blank_len(&input[index]);

	if (!(my_strncmp(&input[index], "node", len - 1)))
	{
		index += len;

		index += index_next_word(&input[index]);
		len = not_blank_len(&input[index]);

		nid = atoi(&input[index]);
        if (check_nodes(*head, nid))
            printf("%s\n", error2);
        else
            append_node(head, new_node(nid));
	}
	else if (!(my_strncmp(&input[index], "block", len - 1)))
	{
		index += len;

		index += index_next_word(&input[index]);
		len = not_blank_len(&input[index]);
		bid = (char*)malloc(sizeof(char) * len + 1);
		my_strncpy(bid, &input[index], len);
        bid[len] = '\0';

		index += not_blank_len(&input[index]);
		index += index_next_word(&input[index]);
		len = not_blank_len(&input[index]);

        if (check_blocks(*head, bid))
        {
            printf("%s\n", error3);
        }
        else
        {
            if (input[index] == '*')
			{
                n_ptr = *head;
                while (n_ptr)
                {
                    append_block(&n_ptr->blocks, new_block(bid));
                    n_ptr = n_ptr->next;
                }
            }
		    else
            {
			    nid = atoi(&input[index]);
                if ((n_ptr = check_nodes(*head, nid)))
			        append_block(&n_ptr->blocks, new_block(bid));
                else
                    printf("%s\n", error4);
            }

        }
		
        free(bid);
        bid = NULL;
	}

	fflush(stdout);
}
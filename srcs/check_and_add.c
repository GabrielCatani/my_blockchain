#include "../includes/my_blockchain.h"

void check_and_add(char *input, node **head)
{
	int nid = 0;
	char *bid = NULL;
	int index = 0;
	int len = 0;

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
        nid = my_atoi(&input[index]);


        if (check_blocks(*head, bid))
        {
            printf("%s\n", error3);
        }
        else if (!(check_nodes(*head, nid)) && my_strncmp(&input[index], "*", 1) != 0)
        {
            printf("%s\n", error4);
        }
        else if (my_strncmp(&input[index], "*", 1) == 0)
        {
            append_block_in_all_nodes(head, new_block(bid));
        }
        else
        {
            append_block_in_node(head, new_block(bid), nid);
        }
	}

	fflush(stdout);
}
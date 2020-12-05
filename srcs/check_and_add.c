#include "../includes/my_blockchain.h"

void check_and_add(char *input)
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
		printf("nid: %d", nid);
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

		if (input[index] == '*')
			printf("add in all nid\n");
		else
        {
			nid = atoi(&input[index]);
			printf("bid: %s\nnid: %d\n", bid, nid);
        }
        free(bid);
        bid = NULL;
	}

	fflush(stdout);
}
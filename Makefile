CC=gcc
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
TARGET=my_blockchain
INCLUDES= includes/my_blockchain.h
OBJECTS= helpers/index_next_word.o helpers/my_atoi.o helpers/my_strcmp.o helpers/my_strcpy.o helpers/my_strlen.o \
		helpers/my_strncmp.o helpers/my_strncpy.o helpers/not_blank_len.o main.o srcs/check_and_add.o \
		srcs/check_and_rm.o helpers/my_strjoin.o helpers/my_strdup.o helpers/my_strsub.o helpers/my_strchr.o \
		helpers/my_strclr.o srcs/my_readline.o srcs/load_ledger.o helpers/is_blank.o srcs/blockchain_status.o \
		srcs/sort_blockchain.o srcs/append_block.o helpers/my_putnbr.o srcs/print_prompt.o srcs/check_and_list.o \
		srcs/new_node.o srcs/new_block.o srcs/append_node.o srcs/check_nodes.o srcs/check_blocks.o srcs/remove_node.o \
		srcs/remove_all_blocks.o srcs/remove_all_nodes.o srcs/append_block_in_all_nodes.o srcs/append_block_in_node.o \
		srcs/remove_block.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJECTS)
	@echo "Linking objects..."

$(OBJECTS): $(INCLUDES)

clean:
	@/bin/rm -f $(OBJECTS)
	@echo "Removing object files..."

fclean: clean
	@/bin/rm -f $(TARGET)
	@echo "Removing binary..."

re: fclean $(TARGET)
	@echo "Recompiling..."

.PHONY: re fclean clean all
.SILENT: $(OBJECTS)







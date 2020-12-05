CC=gcc
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
TARGET=my_blockchain
INCLUDES= includes/my_blockchain.h
OBJECTS= helpers/index_next_word.o helpers/my_atoi.o helpers/my_strcmp.o helpers/my_strcpy.o helpers/my_strlen.o \
		helpers/my_strncmp.o helpers/my_strncpy.o helpers/not_blank_len.o main.o srcs/check_and_add.o srcs/check_and_rm.o

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







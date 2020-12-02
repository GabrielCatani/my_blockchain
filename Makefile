CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
TARGET = my_blockchain

all: $(TARGET)

$(TARGET): 
	$(CC) $(CFLAGS) -o $(TARGET)

re: fclean
	fclean
	$(TARGET)

clean: 
	/bin/rm -f *.o

fclean: clean
	clean
	/bin/rm -f $(TARGET)

.PHONY = all clean fclean re
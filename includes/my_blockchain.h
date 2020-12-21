#ifndef __MY_BLOCKCHAIN_H__
#define __MY_BLOCKCHAIN_H__
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#define READLINE_READ_SIZE 100
#define error1 "1: no more resources available on the computer"
#define error2 "2: this node already exists"
#define error3 "3: this block already exists"
#define error4 "4: node doesn't exist"
#define error5 "5: block doesn't exist"
#define error6 "6: command not found"
#define LEDGER "./test/ledger"
typedef struct block
{
    char *bid;
    struct block *next;
} block;

typedef struct node
{
    int nid;
    int qty_blocks;
    block *blocks;
    struct node *next;
} node;


int not_blank_len(char *word);
char *my_strncpy(char *dst, char *src, size_t len);
int my_strncmp(char *s1, char *s2, size_t len);
int my_strlen(char *str);
char *my_strcpy(char *dst, char *src);
int my_strcmp(char *s1, char *s2);
int my_atoi(char *s);
int index_next_word(char *str);
void check_and_add(char *input, node **head);
void check_and_rm(char *input, node **head);
char *my_strjoin(char *s1, char *s2);
char *my_strdup(char *str);
char *my_strsub(char *str, int start, int len);
char *my_strchr(char *str, char c);
void my_strclr(char **str);
char *my_readline(int fd);
node *load_ledger(int fd);
int is_blank(char c);
void blockchain_status(node *head);
void  sort_blockchain(node **head);
void append_block(block **head, block *n_block);
void  my_putnbr(int nbr);
void  print_prompt(int sync, int nbr_nodes);
void  check_and_list(char *input, node **);
void append_node(node **head, node *n_node);
node *new_node(int nid);
block *new_block(char *bid);
node  *check_nodes(node *head, int nid);
int  check_blocks(node *head, char *bid);
void  remove_all_blocks(node **n_ptr);
void  remove_node(node **head, int nid);
void  remove_all_nodes(node **n_ptr);
void  append_block_in_all_nodes(node **head, char *bid);
void  append_block_in_node(node **head, block *n_block, int nid);
void  remove_block(node **head, char *bid);
block *track_blocks(node *head);
void  sync_nodes(node **head, block *tracked);
int  how_many_digits(int nbr);
void  save_blockchain(node *head);
void  my_itoa(int nbr, int fd, int digits);
void  clear_chain(node **head);
void  clear_tracker(block **b_ptr);
#endif
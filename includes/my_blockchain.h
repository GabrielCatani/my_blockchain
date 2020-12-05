#ifndef __MY_BLOCKCHAIN_H__
#define __MY_BLOCKCHAIN_H__
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#define error1 "1: no more resources available on the computer"
#define error2 "2: this node already exists"
#define error3 "3: this block already exists"
#define error4 "4: node doesn't exist"
#define error5 "5: block doesn't exist"
#define error6 "6: command not found"
typedef struct block
{
    char *bid;
    struct block *next;
} block;

typedef struct node
{
    int nid;
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
void check_and_add(char *input);
void check_and_rm(char *input);
#endif
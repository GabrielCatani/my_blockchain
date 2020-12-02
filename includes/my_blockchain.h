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
typedef struct block_s
{
    char *bid;
    block_s *next;
} block;

typedef struct node_s
{
    int nid;
    block *blocks;
    node_s *next;
} node;



#endif
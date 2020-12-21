#include "../includes/my_blockchain.h"

void front_back_split(block *head, block **front, block **back)
{
    block *slow;
    block *fast;
    slow = head;
    fast = head->next;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

void push_block_front(block **dst, block **src)
{
    block *new;

    new = *src;
    if (new)
    {
        *src = new->next;
        new->next = *dst;
        *dst = new;
    }
}

block *merge_sorted(block *a, block *b)
{
    block dummy;
    block *tail;

    tail = &dummy;
    dummy.next = NULL;
    while (1)
    {
        if (!a)
        {
            tail->next = b;
            break;
        }
        else if (!b)
        {
            tail->next = a;
            break;
        }
        if ((my_strcmp(a->bid, b->bid) < 0))
            push_block_front(&(tail->next), &a);
        else
            push_block_front(&(tail->next), &b);
            
        tail = tail->next;
    }

    return dummy.next;
}

void  sort_blocks(block **c_blocks)
{
    block *head = NULL;
    block *a = NULL;
    block *b = NULL;

    head = *c_blocks;

    if (head == NULL || head->next == NULL)
        return;
    
    front_back_split(head, &a, &b);
    sort_blocks(&a);
    sort_blocks(&b);
    *c_blocks = merge_sorted(a, b);
}

void  sort_blockchain(node **head)
{
    node *ptr = NULL;

    ptr = *head;
    while (ptr)
    {
        sort_blocks(&(ptr)->blocks);
        ptr = ptr->next;
    }
}
# my_blockchain

## Introduction ##
    my_blockchain is a program that creates and manages a blockchain. It lets the user add Nodes, that are
resposible for storing Blocks. Following the blockchain logic, each node of the chain must have all blocks
that were added. In case there is a block that is not present in at least one of the nodes, the blockchain is 
out of sync, and must be syncronized - have the block added to all the nodes. 
    The program can create a new blockchain, but also can load up an existing blockchain.

## Usage ##
    When my_blockchain is run, it checks if there is a blockchain to be loaded, otherwise, it starts a new one.
After loading up, it prompts the user, giving some information about the blockchain in the following manner:

```
    $>my_blockchain
    [s0]> 
```
Inside the [ ]:
    
    the first char indicates if the blockchain is syncronized (s), or not (-);
    the second one, indicates how many nodes are in the blockchain;

### Commands ###
    Commands supported by my_blockchain

#### add ####
```
    $>my_blockchain
    [s0]> add node 1
    [s1]> add block 12 1 
```
add is use to add Nodes, or Blocks, to the blockchain. After the 'add' command, the user inputs if it's a
'node' or a 'block'. In case of nodes, tha user inputs the Node Id (nid). In case of blocks, the user inputs the
Block Id (bid), and the nid to be added - '*' can be used to add the block to all the nodes in the chain.

#### rm ####
```
    $>my_blockchain
    [s3]> rm node 1
    [s2]> rm block 12 
```
rm is use to remove Nodes, or Blocks, from the blockchain. After the 'rm' command, the user inputs if it's a
'node' or a 'block'. In case of nodes, tha user inputs the Node Id (nid) - '*' can be used to remove all the nodes
in the chain.. In case of blocks, the user inputs the Block Id (bid), and the bid is removed from all nodes in the chain.

#### ls ####
```
    $>my_blockchain
    [s2]> ls
    1
    2
    [s2]> ls -l
    1: 12, 13
    2: 12, 13 
```
ls lists all the Nodes in the chain. It acceptes the '-l' option, which lists also the blocks inside each node.

#### sync ####
```
    $>my_blockchain
    [-2]> ls -l
    1: 12
    2: 12, 13
    [-2]> sync
    [s2]> ls -l
    1: 12, 13
    2: 12, 13
```
sync, syncs (copy the blocks to the Nodes that don't have them) the blockchain.

#### quit ####
```
    $>my_blockchain
    [s2]>quit
    $>
```
quit, saves the blockchain - if there are any Nodes left - and exits the program.

## Program Structure ##

#### Main #####
 main loads up any blockchain that may be saved in the current directory, named 'ledger'. After that,
 it starts a loop, that will only break, if the user inputs the 'quit' command. Inside this loop,
 user input will be parsed, calling the respective functions for each command (ex:. add_node, add_block, rm_node, etc.)

#### Nodes and Blocks - Data Strcuture ####
Nodes will consist of simple Nodes in a linked-list. The data inside the nodes, will be another linked-list,
with blocks been the nodes:

```
struct Block
{
    char *bid;
    Block *next;
}

struct Node 
{
    int nid;
    Block *blocks;
    Node *next;
}

$>my_blockchain
[-3]> ls -ls
1: 12, 23
2: 12, 23
3: 12


nid_1 -> nid_2 -> nid_3 -> NULL;
  |        |        |
  v        v        v
 bid_12  bid_12    bid_12
  |        |        |
  v        v        v
 bid_23  bid_23.   NULL
  |        |        
  v        v
 NULL     NULL           
```
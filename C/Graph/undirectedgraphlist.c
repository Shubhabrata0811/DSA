#include<stdio.h>

/*
use adjacency list for sparce graph
    ->space O(e) where e = |E|
    ->find if two nodes are connected - we need to check a single row and do search operation - O(v)
        -linear search: O(v)
        -binary search: O(log v) *if sorted*
    ->find adjacency node - O(v)
    ->add a new edge or delete we add new elements to the specific rows
        -for array it's very expecive
        -for linked list add new element


*/

typedef struct{
    int data;//the other vertex of the node
    int weight;
    struct node* next;
}node;//scapce complexity O(|E|+|V|)
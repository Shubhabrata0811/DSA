#include<stdio.h>

/*
Here in this method we use two lists one Vertex and another Edges of edge type
*/
// typedef struct{
//     char *firstvertex;
//     char *secondvertex;
//     int weight;
// }edge;

typedef struct{
    int v1indx; //use the index to refer the vertex in the vertex list
    int v2indx;
    int weight;
}edge;

/*
Q1. How much time will be taken to find all nodes adjacent to a given node?
ans: Linear search through the Edge List. Time complexity would be O(|E|).

Q2. Check the given nodes are directly connected or not.
ans: Linear search through the Edge List. Worst case time complexity is O(|E|).

**Expected number of edges**
G = (V,E)
let |V| = n
then for simple graph i.e. graph without self loop and multi edge,
    0<=|E|<=n(n-1) **directed graph**
    0<=|E|<=(n(n-1))/2 **undirected graph**
    i.e. we can say |E| can be order of (n^2)
*makes this very costly
*/
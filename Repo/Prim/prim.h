/*  @file prim.h
*   @author Andrei Negret - grupa CR 1.3. A
*   @brief reprezinta definitiile functilor implementate in prim.c
*/

#ifndef PRIM_H_INCLUDED
#define PRIM_H_INCLUDED

//Structura de date folosita pentru a stoca informatii despre un varf
typedef struct {
    char label[255];
    int index;
} vertex;

int computeMinimumCostEdge(int list[], int mstSet[], int V);
int prim(vertex *verticesList, int **adjancencyLists, int *mstSet, vertex *minimumSpanningTree, int V);
void print(vertex *minimumSpanningTree, int k);
void readGraph(vertex *verticesList, int **adjancencyLists, int *mstSet, int V);
void freeResources(int **adjancencyLists, vertex *verticesList, int *mstSet, vertex *minimumSpanningTree, int V);

#endif // PRIM_H_INCLUDED
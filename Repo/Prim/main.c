/*  @file main.c
*   @author Andrei Negret - grupa CR 1.3. A
*   @brief de aici se incepe executia programului c
*/

#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

int main()
{
    int V;
    printf("Numarul de varfuri : ");
    scanf("%d", &V);
    vertex * verticesList = malloc(V * sizeof(vertex));
    vertex * minimumSpanningTree = malloc(V * sizeof(vertex));
    int **adjancencyLists = malloc(V * sizeof(int*));
    int *mstSet = malloc(V * sizeof(int));

    readGraph(verticesList, adjancencyLists, mstSet, V);
    int k = prim(verticesList, adjancencyLists, mstSet, minimumSpanningTree, V);
    print(minimumSpanningTree, k);
    freeResources(adjancencyLists, verticesList, mstSet, minimumSpanningTree, V);
    return 0;
}
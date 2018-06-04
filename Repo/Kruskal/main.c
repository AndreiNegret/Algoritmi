/*  @file main.c
*   @author Andrei Negret - grupa CR 1.3. A
*   @brief de aici se incepe executia programului c
*/
#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

int main()
{
    int n;
    printf("Numarul de varfuri : ");
    scanf("%d", &n);
    vertex * verticesList = malloc(n * sizeof(vertex));
    int **Graph = malloc(n * sizeof(int*));

    readGraph(verticesList, n, Graph);
    kruskal(Graph, n);
    print(verticesList, n);
	return 0;
}

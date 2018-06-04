/*  @file kruskal.c
*   @author Andrei Negret - grupa CR 1.3. A
*   @brief implementeaza functiile necesare pentru algoritmul lui Kruskal
*/
#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

edgeList spanningTree, edges;

/*
*    Calculeaza spanning tree folosind o multime disjuncta ca set de date pentru a determina existenta unui ciclu in graf
*    @param Graph reprezentarea grafului ca un array de liste de adiacenta
*    @param n numarul de varfuri din graf
*/
void kruskal(int **Graph, int n)
{
    int disjointSet[MAX], i, j, findU, findV;
    edges.n = 0;
    for(i = 1; i < n; i++) {
        for(j = 0; j < i; j++)
        {
            if(Graph[i][j] != 0)
            {
                edges.data[edges.n].u = i;
                edges.data[edges.n].v = j;
                edges.data[edges.n].w = Graph[i][j];
                edges.n++;
            }
        }
	}
    sort();
    for(i = 0; i < n; i++) {
        disjointSet[i] = i;
	}
    spanningTree.n = 0;
    for(i = 0; i < edges.n; i++){
        findU = find(disjointSet, edges.data[i].u);
        findV = find(disjointSet, edges.data[i].v);
        if(findU != findV)
        {
            spanningTree.data[spanningTree.n] = edges.data[i];
            spanningTree.n = spanningTree.n + 1;
            setUnion(disjointSet, n, findU, findV);
        }
    }
}

/*
*    Gaseste indexul varfului dat ca parametru, in mutimea disjuncta
*    @param disjointSet multimea disjuncta folosita pentru a gasi un ciclu in graf
*    @param V indexul elementului din multimea disjointSet pe care vrem sa-l interogam
*/
int find(int disjointSet[], int V)
{
    return(disjointSet[V]);
}

/*
*    Uneste doua varfuri din graf in multimea disjuncta in functie de cum au fost vizitate nodurile
*    Se foloseste pentru a determina existenta unui ciclu in graf
*    @param disjointSet multimea disjuncta folosita pentru a gasi un ciclu in graf
*    @param n numarul de varfuri din graf
*    @param n1 primul varf din graf
*    @param n2 al doilea varf din graf
*/
void setUnion(int disjointSet[], int n, int n1, int n2)
{
    int i;
    for(i = 0; i < n; i++) {
        if(disjointSet[i] == n2) {
            disjointSet[i] = n1;
		}
	}
}

/*
*    Sorteaza muchile din graf in ordinea costurilor
*
*/
void sort()
{
    int i, j;
    edge temp;
    for(i = 1; i < edges.n; i++) {
		for(j = 0; j < edges.n-1; j++) {
            if(edges.data[j].w > edges.data[j+1].w)
            {
                temp = edges.data[j];
                edges.data[j] = edges.data[j+1];
                edges.data[j+1] = temp;
            }
		}
	}
}

/*
*   Citeste graful ca liste de adiacenta alocand dinamic resursele necesare
*
*/
void readGraph(vertex *verticesList, int n, int **Graph){
    int i, j;
    //Citeste graful ca liste de adiacenta
    for(i = 0; i < n; i++){
        vertex v;
        printf("Varf : ");
        scanf("%s", v.label);
        v.index = i;
        verticesList[i] = v;
        Graph[i] = malloc(n * sizeof(int));
        printf("Lista de adiacenta pentru %s : \n", v.label);
        for(j = 0; j < n; j++){
            if(j != i) {
                scanf("%d", &Graph[i][j]);
            }
        }
    }
}

/*
*   Afiseaza arborele de cost minim
*   @param verticesList lista de varfuri din graf
*   @param n numarul de varfuri din graf
*/
void print(vertex *verticesList, int n)
{
    int i, cost = 0;
    printf("Arborele de cost minim : \n");
    for(i = 0; i < spanningTree.n; i++)
    {
        printf("%s -> %s (%d)\n", verticesList[spanningTree.data[i].u].label, verticesList[spanningTree.data[i].v].label, spanningTree.data[i].w);
        cost = cost + spanningTree.data[i].w;
    }

    printf("\n\nCostul arborelui : %d", cost);
}

/*
*   Elibereaza resursele alocate dinamic
*   @param Graph reprezentarea grafului ca un array de liste de adiacenta
*   @param verticesList lista de varfuri din graf
*/
void freeResources(int **Graph, vertex *verticesList){
    free(Graph);
    free(verticesList);
}

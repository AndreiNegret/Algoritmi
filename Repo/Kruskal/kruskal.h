/*  @file krukal.h
*   @author Andrei Negret - grupa CR 1.3. A
*   @brief reprezinta definitiile functilor implementate in kruskal.c
*/

#ifndef KRUSKAl_H_INCLUDED
#define KRUSKAl_H_INCLUDED

#define MAX 100

//Structura de date folosita pentru a stoca informatii despre un varf
typedef struct {
    char label[255];
    int index;
} vertex;

//Structura de date folosita pentru a reprezenta o muchie
typedef struct edge
{
    int u, v, w;
} edge;

//Structura de date folosita pentru a reprezenta o lista de muchii din graf
typedef struct edgeList
{
    edge data[MAX];
    int n;
}edgeList;

void sort();
int  find(int disjointSet[], int V);
void setUnion(int disjointSet[], int n, int n1, int n2);
void kruskal(int **Graph, int n);
void readGraph(vertex *verticesList, int n, int **Graph);
void print(vertex *verticesList, int n);
void freeResources(int **Graph, vertex *verticesList);

#endif // KRUSKAl_H_INCLUDED

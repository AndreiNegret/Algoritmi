/*  @file prim.c
*   @author Andrei Negret - grupa CR 1.3. A
*   @brief implementeaza functiile necesare pentru algoritmul lui Prim
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "prim.h"

/* Functie folosita pentru a gasi pentru un varf costul minim al unei muchii
*  formata de acel varf impreuna cu alte noduri si care nu afla in multimea MST(varfurile care afla deja in arborele partial de cost minim)
*  @param list lista de varfuri
*  @param mstSet multimea de varfuri care se afla deja in arbore
*  @param V numarul de varfuri din graf
*/
int computeMinimumCostEdge(int list[], int mstSet[], int V){
    int min = INT_MAX, index, i;
    for(i = 0; i < V; i++){
        if(list[i] && min > list[i] && !mstSet[i]){
            min = list[i];
            index = i;
        }
    }
    return index;
}

/* Calculeaza arborele partial de cost minim folosind algoritmul lui Prim
*  @param verticesList lista de varfuri
*  @param adjancencyLists array-ul de liste de adiacenta reprezentand graful
*  @param minimumSpanningTree referinta catre arborele de cost minim care va fi calculat de algoritm
*  @param V numarul de varfuri din graf
*/
int prim(vertex *verticesList, int **adjancencyLists, int *mstSet, vertex *minimumSpanningTree, int V) {
    int i, j, k = 0;
    // Alege un varf aleator prima data
    int currentVertexIndex = rand() % V;
    mstSet[currentVertexIndex] = 1;
    minimumSpanningTree[k++] = verticesList[currentVertexIndex];
    for(i = 0; i < V-1; i++){
        currentVertexIndex = computeMinimumCostEdge(adjancencyLists[currentVertexIndex], mstSet, V);
        if(mstSet[currentVertexIndex] == 1){
            for(j = 0; j < V; j++){
                if(!mstSet[verticesList[j].index]){
                    currentVertexIndex = verticesList[j].index;
                    break;
                }
            }
        }
        mstSet[currentVertexIndex] = 1;
        minimumSpanningTree[k++] = verticesList[currentVertexIndex];
    }
    return k;
}

/* Citeste graful ca liste de adiacenta alocand dinamic resursele necesare
*  @param verticesList lista de varfuri
*  @param adjancencyLists array-ul de liste de adiacenta reprezentand graful
*  @param mstSet multimea de varfuri care se afla deja in arbore
*  @param V numarul de varfuri din graf
*/
void readGraph(vertex *verticesList, int **adjancencyLists, int *mstSet, int V){
    int i, j;
    for(i = 0; i < V; i++){
        vertex v;
        mstSet[i] = 0;
        printf("Varf : ");
        scanf("%s", v.label);
        v.index = i;
        verticesList[i] = v;
        adjancencyLists[i] = malloc(V * sizeof(int));
        printf("Lista de adiacenta pentru %s : \n", v.label);
        for(j = 0; j < V; j++){
            if(j != i) {
                scanf("%d", &adjancencyLists[i][j]);
            }
        }
    }
    printf("\n");
    for(i = 0; i < V; i++){
        printf("%s -> ", verticesList[i].label);
        for(j = 0; j < V; j++){
            if(i != j){
                printf("%d ", adjancencyLists[i][j]);
            }
        }
        printf("\n");
    }
}

/* Afiseaza arborele partial de cost minim
*
*/
void print(vertex *minimumSpanningTree, int k){
    printf("\nArborele de cost minim : \n");
    int i;
    for(i = 0; i < k; i++){
        printf("%s", minimumSpanningTree[i].label);
        if(i < k - 1){
            printf(" -> ");
        }
    }
}

/* Elibereaza resursele alocate dinamic
*  @param verticesList lista de varfuri
*  @param adjancencyLists array-ul de liste de adiacenta reprezentand graful
*  @param mstSet multimea de varfuri care se afla deja in arbore
*  @param minimumSpanningTree arborele de cost minim
*  @param V numarul de varfuri din graf
*/
//Elibereaza resursele alocate dinamic
void freeResources(int **adjancencyLists, vertex *verticesList, int *mstSet, vertex *minimumSpanningTree, int V){
    int i;
    for(i = 0; i < V; i++){
        free(adjancencyLists[i]);
    }
    free(adjancencyLists);
    free(verticesList);
    free(mstSet);
    free(minimumSpanningTree);
}

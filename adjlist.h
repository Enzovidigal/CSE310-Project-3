//header file for adjlist.cpp

#include "defn.h"

void graphTableArray(adjList** t, int n);
void insert(int n, adjList **t, int vertex_u, int vertex_v, int weight);
void freeList(adjList** t, int n);

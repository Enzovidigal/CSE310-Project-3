// This cpp file implements the graph data structure in adjacency lists

#include <string.h>
#include <iostream>
#include "adjlist.h"

using namespace std;

//allocates memory to graph table
void graphTableArray(adjList** t, int n){
    //initializes table
    for (int i = 0; i < n; i++){
        t[i] = NULL;
    }
}


//inserts new node into adjacency list
void insert(int n, adjList **t, int vertex_u, int vertex_v, int weight){
    adjList *entry = new adjList[sizeof(adjList)];
    entry->vertex_u = vertex_u;
    entry->vertex_v = vertex_v;
    entry->weight = weight;
    entry->next = NULL;


    if (t[vertex_u] == NULL){
        //inserts node at the head
        t[vertex_u] = entry;
    }
    else{
        //inserts node at the head
        adjList *oldHead = t[vertex_u];
        t[vertex_u] = entry;
        t[vertex_u]->next = oldHead;
    }
}


//deletes memory allocated
void freeList(adjList** t, int n){
    for (int i = 0; i < n; i++){
        adjList* temp = t[i];
        while(temp != NULL)
        {
            adjList* toBeDeleted = temp;
            temp = temp->next;
            delete toBeDeleted;
        }
        t[i] = temp;
    }
}


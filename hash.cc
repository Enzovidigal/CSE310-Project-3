#include <string.h>
#include <iostream>
#include "defn.h"

using namespace std;

//allocates memory to graph table
graph** graphTableArray(int n){
    //creates object of hash table
    graph** table = new graph*[n];

    //initializes hash table
    for (int i = 0; i < n; i++){
        table[i] = NULL;
    }
    return table; //returns table
}


//inserts new node into hash table
void insertHT(int n, graph **t, int vertex_u, int vertex_v, int weight){

    node* adjList = new node[sizeof(adjList)];
    adjList->vertex_v = vertex_v;
    adjList->weight = weight;

    graph *oldHead[vertex_u];
    graph *entry = new graph[n];

    //initializes new node to be inserted
    entry->adjLists = adjList;

    //inserts node at the head
    oldHead[vertex_u] = t[vertex_u];
    t[vertex_u] = entry;
    t[vertex_u]->next = oldHead[vertex_u];
    entry = NULL;


    delete(entry);
    //delete(adjList);
}


//deletes memory allocated to hash table
void freeHash(graph** t, int n){
    for (int i=0; i<n; i++) {
        delete(t[i]);
    }
}


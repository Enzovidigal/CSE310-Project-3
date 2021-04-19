#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct adjList
{
    int vertex_u;
    int vertex_v;
    int weight;
    adjList* next;
};

/*
struct graph
{
    struct node* adjLists;
    struct graph* next;
};
 */




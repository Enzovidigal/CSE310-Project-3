#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct node
{
    int vertex_v;
    int weight;
    struct node* next;
};

struct Graph
{
    int numVertices;
    struct node** adjLists;
};
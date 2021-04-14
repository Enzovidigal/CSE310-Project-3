#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct node
{
    int vertex_v;
    int weight;

};

struct graph
{
    struct node* adjLists;
    struct graph* next;
};


graph** graphTableArray(int n);
void insertHT(int n, graph **t, int vertex_u, int vertex_v, int weight);
void freeHash(graph** t, int n);

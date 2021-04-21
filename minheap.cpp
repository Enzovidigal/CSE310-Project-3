#include <string.h>
#include <iostream>
#include <limits.h>
#include "minheap.h"

using namespace std;

void minHeapify(MinHeap* minHeap, int i){
    //initializes positions of the heap
    int minimum = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[minimum]->dist )
        minimum = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[minimum]->dist )
        minimum = right;

    //checks if min is at the root
    if (minimum != i)
    {
        //swaps minimum node with root
        swap(minHeap->array[i], minHeap->array[minimum]);

        //swaps positions
        minHeap->pos[minHeap->array[minimum]->v] = i;
        minHeap->pos[minHeap->array[i]->v] = minimum;

        minHeapify(minHeap, minimum);
    }
}


MinHeapNode* extractMin(MinHeap* minHeap){
    if (minHeap->size == 0)
        return NULL;

    // Store the root node
    MinHeapNode* root = minHeap->array[0];

    // Replace root node with last node
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    minHeap->size = minHeap->size-1;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(MinHeap* minHeap, int v, int dist){
    // Get the index of v in  heap array
    int i = minHeap->pos[v];

    // Get the node and update its dist value
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->array[i]->v] =(i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swap(minHeap->array[i], minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}


void printArr(int dist[], int n){
    cout << "Vertex  Distance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i+1 << "\t\t" << dist[i] << endl;
    }
}


void dijkstra(adjList** adjacencyList, int src, int n){
    // dist values used to pick
    // minimum weight edge in cut
    int dist[n];

    // minHeap represents set E
    MinHeap* minHeap = new MinHeap[sizeof(MinHeap)];
    minHeap->pos = new int[n* sizeof(int)];
    minHeap->size = 0;
    minHeap->array = new MinHeapNode*[(n * sizeof(MinHeapNode*))];


    // Initialize min heap with all
    // vertices. dist value of all vertices
    for (int v = 0; v < n; v++)
    {
        dist[v] = INT_MAX;
        MinHeapNode*  node = new MinHeapNode[sizeof(MinHeapNode)];
        node->v = v;
        node->dist = dist[v];

        minHeap->array[v] = node;
        minHeap->pos[v] = v;
    }

    // Make dist value of src vertex
    // as 0 so that it is extracted first

    MinHeapNode*  newNode = new MinHeapNode[sizeof(MinHeapNode)];
    newNode->v = src;
    newNode->dist = dist[src];

    minHeap->array[src] = newNode;
    minHeap->pos[src]  = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    // Initially size of min heap is equal to V
    minHeap->size = n;

    // In the followin loop,
    // min heap contains all nodes
    // whose shortest distance
    // is not yet finalized.
    while (minHeap->size != 0)
    {
        MinHeapNode* minHeapNode = extractMin(minHeap);

        adjList *temp = adjacencyList[minHeapNode->v];
        while (temp != NULL)
        {
            if (minHeap->pos[temp->vertex_v] < minHeap->size && dist[minHeapNode->v] != INT_MAX && temp->weight + dist[minHeapNode->v] < dist[temp->vertex_v])
            {
                dist[temp->vertex_v] = dist[minHeapNode->v] + temp->weight;

                decreaseKey(minHeap, temp->vertex_v, dist[temp->vertex_v]);
            }
            temp = temp->next;
        }

    }

    // print the calculated shortest distances
    printArr(dist, n);
}


#include "adjlist.h"

struct MinHeapNode
{
    int  v;
    int dist;
};

struct MinHeap
{
    int size;
    int *pos;
    struct MinHeapNode **array;
};

void dijkstra(adjList** adjacencyList, int source, int n);
void minHeapify(MinHeap* minHeap,int i);
MinHeapNode* extractMin(MinHeap* minHeap);
void decreaseKey(MinHeap* minHeap, int v, int dist);
void printArr(int dist[], int n);
//header file for adjlist.cpp

struct adjList
{
    int vertex_u;
    int vertex_v;
    int weight;
    adjList* next;
};

void graphTableArray(adjList** t, int n);
void insert(int n, adjList **t, int vertex_u, int vertex_v, int weight);
void freeList(adjList** t, int n);

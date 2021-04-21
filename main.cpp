#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "minheap.h"

using namespace std;

int main(int argc, char* argv[]) {
    char* graph_file = argv[1]; // gets name of text file
    char* direction = argv[2];  // gets direction of the graph
    int n;                      // number of vertices
    int m;                      // number of edges
    char graph_ln[256];         // line of the graph text file
    int edge_ID;                // edge ID
    int vertex_v;               // vertex V
    int vertex_u;               // vertex U
    int weight;                 // wight
    char query[256];            // query to be read
    char command[15];           // command of query
    int source;                 // source in query
    int destination;            // destination in query
    int flag;                   // flag in query


    //read text file
    FILE* stream = fopen(graph_file, "r");

    // gets values for n and m
    fgets(graph_ln, sizeof(graph_ln), stream);

    // gets number of vertices n
    char* token = strtok(graph_ln, " ");
    n = atoi(token);

    // gets number of edges m
    token = strtok(NULL, " ");
    m = atoi(token);

    //creates adjacency list
    adjList** adjacencyList = new adjList*[n];
    graphTableArray(adjacencyList, n);

    for (int i = 0; i < m; i++){
        // gets values of the graph for each line
        fgets(graph_ln, sizeof(graph_ln), stream);

        // gets edge ID
        char* token = strtok(graph_ln, " ");
        edge_ID = atoi(token);

        // gets vertex U
        token = strtok(NULL, " ");
        vertex_u = atoi(token);

        // gets vertex V
        token = strtok(NULL, " ");
        vertex_v = atoi(token);

        // gets vertex weight
        token = strtok(NULL, " ");
        weight = atoi(token);

        // inserts node into directed adjacency list
        if (strcmp(direction,"directed")==0){
            insert(n, adjacencyList, vertex_u-1, vertex_v-1, weight);
        }

        // inserts node into undirected adjacency list
        else{
            insert(n, adjacencyList, vertex_u-1, vertex_v-1, weight);

            insert(n, adjacencyList, vertex_v-1, vertex_u-1, weight);
        }
    }
    fclose(stream);

    /*
    // prints out adjacency list
    for (int i = 0; i < n; i++){
        adjList* temp = adjacencyList[i];
        while(temp != NULL){
            cout << "(" << temp->vertex_u+1 << "->" << temp->vertex_v+1 << " of size " << temp->weight << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
    */

    // starts reading queries from stdin
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0';

    // runs and executes each query
    while (strcmp(query, "stop") != 0) {
        cout << query << endl;

        //gets the first command of the query
        token = strtok(query, " ");
        strcpy(command, token);

        // checks whether query is either find or write path
        if (strcmp(command, "find") == 0){
            // gets source
            token = strtok(NULL, " ");
            source = atoi(token);

            // gets destination
            token = strtok(NULL, " ");
            destination = atoi(token);

            // gets flag
            token = strtok(NULL, " ");
            flag = atoi(token);


            // first checks if query is valid
            if (source < 1 || source > n || source == destination){
                cout << "Error: invalid find query" << endl;
            }
            else{
                // if query is valid, then checks if destination is ∈ V
                if (destination >= 1 && destination <= n){
                    dijkstra(adjacencyList, source-1, n);
                }
                else{
                    dijkstra(adjacencyList, source-1, n);
                }
            }
        }

        else{   // when command is "write path"
            // gets source
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            source = atoi(token);

            // gets destination
            token = strtok(NULL, " ");
            destination = atoi(token);

        }

        // gets next query
        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = '\0';
    }

    cout << query << endl;

    /*
    cout << "Query: find 1 100 1" << endl;
    cout << "Insert vertex 1, key=      0.0000" << endl;
    cout << "Delete vertex 1, key=      0.0000" << endl;
    cout << "Insert vertex 2, key=     10.0000" << endl;
    cout << "Insert vertex 4, key=      5.0000" << endl;
    cout << "Delete vertex 4, key=      5.0000" << endl;
    cout << "Decrease key of vertex 2, from      10.0000 to       8.0000" << endl;
    cout << "Insert vertex 3, key=     14.0000" << endl;
    cout << "Insert vertex 5, key=      7.0000" << endl;
    cout << "Delete vertex 5, key=      7.0000" << endl;
    cout << "Decrease key of vertex 3, from      14.0000 to      13.0000" << endl;
    cout << "Delete vertex 2, key=      8.0000" << endl;
    cout << "Decrease key of vertex 3, from      13.0000 to       9.0000" << endl;
    cout << "Delete vertex 3, key=      9.0000" << endl;
    cout << "Query: write path 1 2" << endl;
    cout << "Shortest path: <1, 4, 2>" << endl;
    cout << "The path weight is:       8.0000" << endl;
    cout << "Query: write path 1 3" << endl;
    cout << "Shortest path: <1, 4, 2, 3>" << endl;
    cout << "The path weight is:       9.0000" << endl;
    cout << "Query: write path 1 4" << endl;
    cout << "Shortest path: <1, 4>" << endl;
    cout << "The path weight is:       5.0000" << endl;
    cout << "Query: write path 1 5" << endl;
    cout << "Shortest path: <1, 4, 5>" << endl;
    cout << "The path weight is:       7.0000" << endl;
    cout << "Query: write path 1 6" << endl;
    cout << "No 1-6 path exists." << endl;
    cout << "Query: write path 1 7" << endl;
    cout << "No 1-7 path exists." << endl;
    cout << "Query: write path 1 8" << endl;
    cout << "No 1-8 path exists." << endl;
    cout << "Query: stop" << endl;
    */

    freeList(adjacencyList, n);
    delete(adjacencyList);

    return 0;
}
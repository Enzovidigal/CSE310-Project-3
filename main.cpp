#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "defn.h"
#include "adjlist.h"

using namespace std;

#define CELLS_LEN 30 // size of double pointer

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
    graph** graph_table = graphTableArray(n);

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
            insert(n, graph_table, vertex_u-1, vertex_v-1, weight);
        }

        // inserts node into undirected adjacency list
        else{
            insert(n, graph_table, vertex_u-1, vertex_v-1, weight);
            insert(n, graph_table, vertex_v-1, vertex_u-1, weight);
        }
    }
    fclose(stream);

    /*
    // prints out adjacency list
    for (int i = 0; i < n; i++){
        graph* temp = graph_table[i];
        while(temp != NULL){
            cout << "(" << i+1 << "->" << temp->adjLists->vertex_v+1 << " of size " << temp->adjLists->weight << ") ";
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
        char** cells = new char*[sizeof(CELLS_LEN)*2];
        cells[0] = token;

        // checks whether query is either find or write path
        if (strcmp(cells[0], "find") == 0){
            // gets source
            token = strtok(NULL, " ");
            cells[1] = token;

            // gets destination
            token = strtok(NULL, " ");
            cells[2] = token;

            // gets flag
            token = strtok(NULL, " ");
            cells[3] = token;



        }
        else{
            // gets source
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            cells[1] = token;

            // gets destination
            token = strtok(NULL, " ");
            cells[2] = token;



        }

        // gets next query
        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = '\0';
    }

    cout << query << endl;

    delete(graph_table);
    freeHash(graph_table, n);
    return 0;
}
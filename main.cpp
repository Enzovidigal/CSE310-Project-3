#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "defn.h"
#include "adjlist.h"

using namespace std;

int main(int argc, char* argv[]) {
    char* graph_file = argv[1];      // gets name of text file
    char* direction = argv[2];  // gets direction of the graph
    int n;                      // number of vertices
    int m;                      // number of edges
    char graph_ln[256];         // line of the graph text file
    int edge_ID;                // edge ID
    int vertex_v;               // vertex V
    int vertex_u;               // vertex U
    int weight;                 // wight

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

        if (strcmp(direction,"directed")==0){
            insert(n, graph_table, vertex_u-1, vertex_v-1, weight);
        }
        else{
            insert(n, graph_table, vertex_u-1, vertex_v-1, weight);
            insert(n, graph_table, vertex_v-1, vertex_u-1, weight);
        }
    }

    for (int i = 0; i < n; i++){
        graph* temp = graph_table[i];
        while(temp != NULL){
            cout << "(" << i+1 << "->" << temp->adjLists->vertex_v+1 << " of size " << temp->adjLists->weight << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    delete(graph_table);
    freeHash(graph_table, n);
    fclose(stream);
    return 0;
}
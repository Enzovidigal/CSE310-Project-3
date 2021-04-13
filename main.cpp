#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "defn.h"

using namespace std;

int main(int argc, char* argv[]) {
    char* graph = argv[1];      // gets name of text file
    char* direction = argv[2];  // gets direction of the graph
    int n;                      // number of vertices
    int m;                      // number of edges
    char first_ln[256];         // first line of the graph text file

    //read text file
    FILE* stream = fopen(graph, "r");

    if (stream != NULL) {
        // gets values for n and m
        fgets(first_ln, sizeof(first_ln), stream);
        char* token = strtok(first_ln, " ");
        n = atoi(token);

        token = strtok(NULL, " ");
        m = atoi(token);



        fclose(stream);
    }
    return 0;
}
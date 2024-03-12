#include <iostream>
#include <fstream>
#include "Graph.h"

int main() {

    ifstream source;
    source.open("C:/Users/yashn/OneDrive/Documents/bidirectionalDijekstra.txt");

    if (!source.is_open()) {
        cout << "No file" << endl;
        return 0;
    }

    int V;
    source >> V;
    Graph myGraph(V);

    int V1, V2, W;
    while (source >> V1 >> V2 >> W) {
        myGraph.addEdge(V1, V2, W);
    }

    myGraph.printGraphL();
    myGraph.toMatrix();

    cout << "Adjency matrix:" << endl;
    myGraph.printGraphM();

    cout << "Bidirectional Dijkstra:\n";
    cout << myGraph.bidirectionalDijkstra(0, 0) << endl;
    cout << myGraph.bidirectionalDijkstra(0, 1) << endl;
    cout << myGraph.bidirectionalDijkstra(0, 2) << endl;
    cout << myGraph.bidirectionalDijkstra(0, 3) << endl;
    cout << myGraph.bidirectionalDijkstra(0, 4) << endl;



    source.close();
    return 0;
}

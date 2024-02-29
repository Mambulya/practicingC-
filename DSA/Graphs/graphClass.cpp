#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Edge {
    int destination;
    int weight;
    Edge(int dest, int w) {
        destination = dest;
        weight = w;
    }
};

class Graph {
private:
    int numV;
    vector<vector<Edge>> adjList;
    int** adjMatrix = new int* [numV];

public:
    Graph(int verticles) {
        this->numV = verticles;
        adjList.resize(numV);
    }

    void addEdge(int fromV, int toV, int weight) {
        adjList[fromV].push_back(Edge(toV, weight));
    }

    void removeEdge(int fromV, int toV) {
        for (auto it = adjList[fromV].begin(); it != adjList[fromV].end(); it++) {
            if (it->destination == toV) {
                adjList[fromV].erase(it);
                break;
            }      
        }
    }


    void printGraphL() {
        cout << "Graph:\n";
        for (int i = 0; i < numV; ++i) {
            for (const Edge& edge : adjList[i]) {
                cout << i << " -> " << edge.destination << " W: " << edge.weight << endl;
            }
        }
    }

    void toMatrix() {
        for (int i = 0; i < numV; ++i) {
            adjMatrix[i] = new int[numV];
        }

        for (int i = 0; i < numV; i++) {
            for (int j = 0; j < numV; j++) {
                adjMatrix[i][j] = 0;
            }
        }

        for (int i = 0; i < numV; i++) {
            for (Edge edge : adjList[i]) {
                adjMatrix[i][edge.destination] = edge.weight;
            }
        }
    }

    void printGraphM() {

        for (int i = 0; i < numV; i++) {
            for (int j = 0; j < numV; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    
    ifstream source;
    source.open("C:/Users/yashn/OneDrive/Documents/bidirectionalDijekstra.txt");

    if (!source.is_open()) {
        cout << "No file" << endl;
        return 0;
    }
    
    int V;
    source >> V;
    Graph graph(V);

    int V1, V2, W;
    while (source >> V1 >> V2 >> W) {
        graph.addEdge(V1, V2, W);
    }
        
    graph.printGraphL();
    graph.toMatrix();

    cout << "Adjency matrix:" << endl;
    graph.printGraphM();

    source.close();
    return 0;
}


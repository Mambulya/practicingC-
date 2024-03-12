#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <limits>
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
    vector<vector<Edge>> reversedList;

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

    void reverse() {
        reversedList.resize(numV);
        for (int v = 0; v < numV; v++) {
            for (const Edge& edge : adjList[v]) {
                reversedList[edge.destination].push_back(Edge(v, edge.weight));
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


    int bidirectionalDijkstra(int source, int target) {
        if (source == target)
            return 0;

        // Инициализация расстояний от начальной и конечной вершин до всех остальных вершин как бесконечность
        vector<int> distSource(numV, numeric_limits<int>::max());
        vector<int> distTarget(numV, numeric_limits<int>::max());

        distSource[source] = 0;
        distTarget[target] = 0;

        // Создание приоритетных очередей для вершин из начальной и конечной вершин
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqSource;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqTarget;

        pqSource.push({ 0, source });
        pqTarget.push({ 0, target }); 

        this->reverse();

        while (!pqSource.empty() && !pqTarget.empty()) {
            // Поочередно запускаем Дейкстры
            int distanceSource = dijkstra(pqSource, distSource, distTarget, adjList); // frontDijkstra
            if (distanceSource != -1)   // если frontDijkstra встретилась с backDijkstra
                return distanceSource;

            int distanceTarget = dijkstra(pqTarget, distTarget, distSource, reversedList); // backDijkstra
            if (distanceTarget != -1)   // если backDijkstra встретилась с frontDijkstra
                return distanceTarget;
        }

        // Если пути не найдены
        return -1;
    }

    private:
        // Вспомогательная функция для двухстороннего алгоритма Дейкстры
        int dijkstra(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq,
            vector<int>& dist,
            const vector<int>& otherDist, vector<vector<Edge>> list) {

            int minDist = numeric_limits<int>::max();
            int u = pq.top().second;
            pq.pop();

            // Обходим всех соседей вершины u
            for (const Edge& edge : list[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                // Если нашли более короткий путь к вершине v, обновляем расстояние
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });

                    // Если найденное расстояние до вершины v = бесконечность,
                    // значит вторая дейкстра до неё еще не дошла
                    if (otherDist[v] != numeric_limits<int>::max())
                        minDist = min(dist[v] + otherDist[v], minDist);  // складываем пути
                }
            }
            if (minDist != numeric_limits<int>::max())
                return minDist;
            return -1;  // дейкстры ещё не встретились
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

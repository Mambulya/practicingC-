```
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


    // Алгоритм Дейкстры для поиска кратчайших путей от исходной вершины src до всех остальных вершин
    vector<int> dijkstra(int src) {
        vector<int> dist(numV, numeric_limits<int>::max()); // расстояния до всех вершин как бесконечность
        dist[src] = 0; // 

        // Создаем возрастающую приоритетную очередь из (dist(s), s)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, src });

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // Обходим всех соседей вершины u
            for (const Edge& edge : adjList[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                // Если нашли более короткий путь к вершине v, обновляем расстояние
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }

        return dist;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Двухсторонний алгоритм Дейкстры для поиска кратчайшего пути между начальной и конечной вершинами
    int bidirectionalDijkstra(int source, int target) {
        // Инициализация расстояний от начальной и конечной вершин до всех остальных вершин как бесконечность
        vector<int> distSource(numV, numeric_limits<int>::max());
        vector<int> distTarget(numV, numeric_limits<int>::max());

        // Инициализация расстояний от начальной и конечной вершин до самих себя как 0
        distSource[source] = 0;
        distTarget[target] = 0;

        // Создание приоритетных очередей для вершин из начальной и конечной вершин
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqSource;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqTarget;

        pqSource.push({ 0, source }); // Добавляем начальную вершину в очередь с расстоянием 0
        pqTarget.push({ 0, target }); // Добавляем конечную вершину в очередь с расстоянием 0

        while (!pqSource.empty() && !pqTarget.empty()) {
            // Поочередно ищем кратчайшие пути от начальной и конечной вершин
            int distanceSource = bidirectionalDijkstraHelper(pqSource, distSource, distTarget);
            if (distanceSource != -1)
                return distanceSource;

            int distanceTarget = bidirectionalDijkstraHelper(pqTarget, distTarget, distSource);
            if (distanceTarget != -1)
                return distanceTarget;
        }

        // Если пути не найдены
        return -1;
    }

    private:
        // Вспомогательная функция для двухстороннего алгоритма Дейкстры
        int bidirectionalDijkstraHelper(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq,
            vector<int>& dist,
            const vector<int>& otherDist) {
            int u = pq.top().second;
            pq.pop();

            // Обходим всех соседей вершины u
            for (const Edge& edge : adjList[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                // Если нашли более короткий путь к вершине v, обновляем расстояние
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });

                    // Если найденное расстояние до вершины v меньше, чем текущее расстояние от другой стороны,
                    // значит, мы нашли кратчайший путь между начальной и конечной вершинами
                    if (otherDist[v] != numeric_limits<int>::max())
                        return dist[v];
                }
            }

            return -1;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


    // Вызов алгоритма Дейкстры для поиска кратчайших путей от вершины 0
    cout << "\nThe length from verticle #0 to other verticles:\n";
    vector<int> distances = graph.dijkstra(0);
    for (int i = 0; i < distances.size(); ++i) {
        cout << "The length from the verticle # " << i << " = " << distances[i] << endl;
    }

    source.close();
    return 0;
}
```

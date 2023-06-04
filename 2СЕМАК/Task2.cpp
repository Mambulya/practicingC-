
#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

vector<pair<int, int> > graph[100005];
int dist[100005], parent[100005];
bool visited[100005];

void dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    if (dist[end] == INF) {
        cout << "No path found!" << endl;
    } else {
        cout << "Shortest distance: " << dist[end] << endl;
        cout << "Shortest path: ";
        vector<int> path;
        for (int v = end; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    dijkstra(start, end);
    return 0;
}

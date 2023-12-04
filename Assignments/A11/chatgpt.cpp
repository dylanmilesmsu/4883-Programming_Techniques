#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int dest, weight;
};

// Structure to represent a vertex and its distance from the source
struct Vertex {
    int id, distance;
};

bool operator>(const Vertex &a, const Vertex &b) {
    return a.distance > b.distance;
}

// Function to find the shortest distance using Dijkstra's algorithm
vector<int> dijkstra(const vector<vector<Edge>> &graph, int start) {
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max());
    distance[start] = 0;

    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        Vertex current = pq.top();
        pq.pop();

        for (const Edge &neighbor : graph[current.id]) {
            int newDistance = current.distance + neighbor.weight;
            if (newDistance < distance[neighbor.dest]) {
                distance[neighbor.dest] = newDistance;
                pq.push({neighbor.dest, newDistance});
            }
        }
    }

    return distance;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<Edge>> graph(vertices);

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < edges; ++i) {
        int source, dest, weight;
        cin >> source >> dest >> weight;
        graph[source].push_back({dest, weight});
        graph[dest].push_back({source, weight}); // Assuming an undirected graph
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    vector<int> distances = dijkstra(graph, startVertex);

    cout << "Shortest distances from vertex " << startVertex << " to all other vertices:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "To vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}

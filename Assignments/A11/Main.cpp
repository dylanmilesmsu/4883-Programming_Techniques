#include <iostream>
#include <vector>
#include <algorithm>
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
int dijkstra(const vector<vector<Edge>> &graph, int start, int end) {
    //edge case found on udebug
    if(start == end)
        return 0;
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max());
    distance[start] = 0;
    int interestedDistance = -1;
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
                if(neighbor.dest == end) {
                    interestedDistance = newDistance;
                }
            }
        }
    }

    return interestedDistance;
}

void printMap(vector<Edge> edges) {
    int i = 0;
    for(Edge e : edges) {
        cout << i << " -> " << e.dest << " @ " << e.weight << "ms\n";
        i++;
    }
}

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {

        int amountOfservers;
        cin >> amountOfservers;
        int cables;
        cin >> cables;
        int startServer;
        cin >> startServer;
        int endServer;
        cin >> endServer;

        int vertices, edges;
        vertices = amountOfservers;
        edges = cables;

        vector<vector<Edge>> graph(vertices);
        for(int x = 0; x < cables; x++) {
            int source;
            cin >> source;
            int dest;
            cin >> dest;
            int lag;
            cin >> lag;
            graph[source].push_back({dest, lag});
            graph[dest].push_back({source, lag}); // Assuming an undirected graph
        }
        int startVertex = startServer;
        int distances = dijkstra(graph, startVertex, endServer);
        if(distances == -1) {
            cout << "Case #" << i+1 << ": unreachable\n";
        } else
            cout << "Case #" << i+1 << ": " << distances << endl;
        // cout << "Shortest distances from vertex " << startVertex << " to all other vertices:" << endl;
        // for (int i = 0; i < vertices; ++i) {
        //     cout << "To vertex " << i << ": " << distances[i] << endl;
        // }
        // cout << "Trying to find path from " << startServer << " to " << endServer << endl;
        // printMap(edges);

    }

    return 0;
}
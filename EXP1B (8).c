#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6   // Number of vertices

// Function to find vertex with minimum distance
int min_dist(int dist[], bool visited[]) {
    int minimum = INT_MAX, index;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= minimum) {
            minimum = dist[i];
            index = i;
        }
    }
    return index;
}

// Dijkstra Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0; // Source vertex distance is 0

    for (int i = 0; i < V - 1; i++) {
        int u = min_dist(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%c\t%d\n", 65 + i, dist[i]);
    }
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };

    dijkstra(graph, 0); // Source vertex A (index 0)

    return 0;
}

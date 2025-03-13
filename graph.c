#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function prototypes
void printAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);
void searchEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v);
void updateEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v, int weight);
void deleteEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v);
void deleteNode(int graph[MAX_VERTICES][MAX_VERTICES], int* vertices, int vertex);
void takeInput(int* vertices, int graph[MAX_VERTICES][MAX_VERTICES]);
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start);
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start, bool visited[MAX_VERTICES]);
bool isCyclicUtil(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int v, bool visited[MAX_VERTICES], int parent);
bool isCyclic(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int vertices = 0, choice, u, v, weight;

    takeInput(&vertices, graph);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Print adjacency matrix\n");
        printf("2. Search for an edge\n");
        printf("3. Update an edge\n");
        printf("4. Delete an edge\n");
        printf("5. Delete a node (vertex) and its edges\n");
        printf("6. BFS (Breadth First Search)\n");
        printf("7. DFS (Depth First Search)\n");
        printf("8. Check if graph is cyclic\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printAdjacencyMatrix(graph, vertices);
                break;
            case 2:
                printf("Enter two vertices to search for an edge (u, v): ");
                scanf("%d %d", &u, &v);
                searchEdge(graph, u, v);
                break;
            case 3:
                printf("Enter two vertices to update edge (u, v) and weight: ");
                scanf("%d %d %d", &u, &v, &weight);
                updateEdge(graph, u, v, weight);
                break;
            case 4:
                printf("Enter two vertices to delete edge (u, v): ");
                scanf("%d %d", &u, &v);
                deleteEdge(graph, u, v);
                break;
            case 5:
                printf("Enter vertex to delete: ");
                scanf("%d", &u);
                deleteNode(graph, &vertices, u);
                break;
            case 6:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &u);
                bfs(graph, vertices, u);
                break;
            case 7:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &u);
                bool visited[MAX_VERTICES] = {false};
                dfs(graph, vertices, u, visited);
                printf("\n");
                break;
            case 8:
                if (isCyclic(graph, vertices)) {
                    printf("Graph is cyclic.\n");
                } else {
                    printf("Graph is acyclic.\n");
                }
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to input graph edges and initialize adjacency matrix
void takeInput(int* vertices, int graph[MAX_VERTICES][MAX_VERTICES]) {
    int edges, u, v, weight;

    printf("Enter number of vertices: ");
    scanf("%d", vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);

        if (u < *vertices && v < *vertices && u != v) {
            graph[u][v] = weight;
        } else {
            printf("Invalid edge. Please try again.\n");
            i--;  // Retry this edge input
        }
    }
}

// Function to print adjacency matrix as an adjacency list
void printAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Adjacency List:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d -> [", i);

        bool hasNeighbor = false; // To handle case when there are no neighbors
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] != 0) { // There is an edge between vertex i and vertex j
                if (hasNeighbor) {
                    printf(", ");
                }
                printf("%d", j);
                hasNeighbor = true;
            }
        }

        if (!hasNeighbor) {
            printf("No neighbors");
        }
        
        printf("]\n");
    }
}

// Function to search for an edge between two vertices
void searchEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    if (graph[u][v] != 0) {
        printf("Edge exists between %d and %d with weight %d\n", u, v, graph[u][v]);
    } else {
        printf("No edge exists between %d and %d\n", u, v);
    }
}

// Function to update the weight of an edge between two vertices
void updateEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v, int weight) {
    if (graph[u][v] != 0) {
        graph[u][v] = weight;
        graph[v][u] = weight;  // For undirected graph
        printf("Edge updated between %d and %d with new weight %d\n", u, v, weight);
    } else {
        printf("No edge exists between %d and %d to update\n", u, v);
    }
}

// Function to delete an edge between two vertices
void deleteEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    if (graph[u][v] != 0) {
        graph[u][v] = 0;
        graph[v][u] = 0;  // For undirected graph
        printf("Edge deleted between %d and %d\n", u, v);
    } else {
        printf("No edge exists between %d and %d to delete\n", u, v);
    }
}

// Function to delete a node (vertex) and its associated edges
void deleteNode(int graph[MAX_VERTICES][MAX_VERTICES], int* vertices, int vertex) {
    if (vertex >= *vertices || vertex < 0) {
        printf("Invalid vertex!\n");
        return;
    }

    // Set the row and column of the deleted vertex to 0 to remove it
    for (int i = 0; i < *vertices; i++) {
        graph[vertex][i] = 0;  // Remove edges from this node
        graph[i][vertex] = 0;  // For undirected graph, also remove edges to this node
    }

    // Optionally, mark the node as "deleted" by decreasing the vertex count
    // But we will keep the matrix size the same, and just ignore this node in future operations.
    printf("Node %d and its associated edges have been 'removed'\n", vertex);
}

// Function for Breadth First Search (BFS)
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;

    printf("BFS starting from vertex %d: ", start);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] != 0 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// Function for Depth First Search (DFS)
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start, bool visited[MAX_VERTICES]) {
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] != 0 && !visited[i]) {
            dfs(graph, vertices, i, visited);
        }
    }
}

// Function to check if the graph is cyclic (using DFS)
bool isCyclicUtil(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int v, bool visited[MAX_VERTICES], int parent) {
    visited[v] = true;

    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] != 0) {
            if (!visited[i]) {
                if (isCyclicUtil(graph, vertices, i, visited, v)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if the graph is cyclic
bool isCyclic(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    bool visited[MAX_VERTICES] = {false};

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, vertices, i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}
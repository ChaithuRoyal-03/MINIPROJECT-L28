This C program allows basic graph operations using an adjacency matrix. It includes functionalities to add/remove edges, update edge weights, perform BFS/DFS, and check if the graph is cyclic.

Features
Print Adjacency Matrix: Display the graph in an adjacency list format.

Search Edge: Check if an edge exists between two vertices.

Update Edge: Modify the weight of an existing edge.

Delete Edge: Remove an edge between two vertices.

Delete Node: Remove a vertex and its associated edges.

BFS: Perform a Breadth-First Search starting from a vertex.

DFS: Perform a Depth-First Search starting from a vertex.

Check Cyclicity: Check if the graph contains a cycle.



How to Use
Compile: gcc -o graph_operations graph_operations.c
Run: ./graph_operations


Menu Options:
Print adjacency matrix
Search for an edge
Update an edge
Delete an edge
Delete a vertex and its edges
Perform BFS or DFS
Check if the graph is cyclic
Exit


Output:
Enter number of vertices: 5
Enter number of edges: 5
Enter edge 1 (u v weight): 0 1 10
Enter edge 2 (u v weight): 1 2 20
Enter edge 3 (u v weight): 2 3 30
Enter edge 4 (u v weight): 3 4 40
Enter edge 5 (u v weight): 0 4 50

Menu:
1. Print adjacency matrix
2. Search for an edge
3. Update an edge
4. Delete an edge
5. Delete a node (vertex) and its edges
6. BFS (Breadth First Search)
7. DFS (Depth First Search)
8. Check if graph is cyclic
9. Exit

Enter your choice: 1
Adjacency List:
Vertex 0 -> [1, 4]
Vertex 1 -> [2]
Vertex 2 -> [3]
Vertex 3 -> [4]
Vertex 4 -> [No neighbors]

Menu:
1. Print adjacency matrix
2. Search for an edge
3. Update an edge
4. Delete an edge
5. Delete a node (vertex) and its edges
6. BFS (Breadth First Search)
7. DFS (Depth First Search)
8. Check if graph is cyclic
9. Exit
    
Enter your choice: 2
Enter two vertices to search for an edge (u, v): 0 1
Edge exists between 0 and 1 with weight 10

Menu:
1. Print adjacency matrix
2. Search for an edge
3. Update an edge
4. Delete an edge
5. Delete a node (vertex) and its edges
6. BFS (Breadth First Search)
7. DFS (Depth First Search)
8. Check if graph is cyclic
9. Exit
    
Enter your choice: 3
Enter two vertices to update edge (u, v) and weight: 0 1 15
Edge updated between 0 and 1 with new weight 15

Menu:
1. Print adjacency matrix
2. Search for an edge
3. Update an edge
4. Delete an edge
5. Delete a node (vertex) and its edges
6. BFS (Breadth First Search)
7. DFS (Depth First Search)
8. Check if graph is cyclic
9. Exit
    
Enter your choice: 4
Enter two vertices to delete edge (u, v): 2 3
Edge deleted between 2 and 3

Menu:
1. Print adjacency matrix
2. Search for an edge
3. Update an edge
4. Delete an edge
5. Delete a node (vertex) and its edges
6. BFS (Breadth First Search)
7. DFS (Depth First Search)
8. Check if graph is cyclic
9. Exit
    
Enter your choice: 5
Enter vertex to delete: 1
Node 1 and its associated edges have been 'removed'

Menu:
1. Print adjacency matrix
2. Search for an edge
3. Update an edge
4. Delete an edge
5. Delete a node (vertex) and its edges
6. BFS (Breadth First Search)
7. DFS (Depth First Search)
8. Check if graph is cyclic
9. Exit
    
Enter your choice: 6
Enter starting vertex for BFS: 0
BFS starting from vertex 0: 0 4 

Menu:
1. Print adjacency matrix
2. Search for an edge
3. Update an edge
4. Delete an edge
5. Delete a node (vertex) and its edges
6. BFS (Breadth First Search)
7. DFS (Depth First Search)
8. Check if graph is cyclic
9. Exit
    
Enter your choice: 7
Enter starting vertex for DFS: 0
0 4 

Menu:
1. Print adjacency matrix
2. Search for an edge
3. Update an edge
4. Delete an edge
5. Delete a node (vertex) and its edges
6. BFS (Breadth First Search)
7. DFS (Depth First Search)
8. Check if graph is cyclic
9. Exit
    
Enter your choice: 8
Graph is cyclic.

Menu:
1. Print adjacency matrix
2. Search for an edge
3. Update an edge
4. Delete an edge
5. Delete a node (vertex) and its edges
6. BFS (Breadth First Search)
7. DFS (Depth First Search)
8. Check if graph is cyclic
9. Exit

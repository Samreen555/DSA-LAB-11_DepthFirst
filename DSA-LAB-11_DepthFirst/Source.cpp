#include <iostream>
#include <string>
#include <limits>
using namespace std;

#define MAX 50

// Node class for linked list to represent edges
class Node {
public:
    int vertex;
    Node* next;

    Node(int v) {
        vertex = v;
        next = nullptr;
    }
};

// Queue class to handle queue operations
class Queue {
private:
    int front, rear;
    int q[MAX];

public:
    bool IsEmpty() {
        return front == -1;
    }

    bool IsFull() {
        return rear == MAX - 1;
    }

    Queue() {
        front = -1;
        rear = -1;
    }

    void insert(int element) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
        }
        else {
            if (front == -1) front = 0;
            q[++rear] = element;
        }
    }

    int deleteElement() {
        if (IsEmpty()) {
            cout << "Queue Underflow\n";
            return -1; // Indicate error
        }
        else {
            int deletedElement = q[front];
            if (front >= rear) { // Reset the queue if it's empty
                front = rear = -1;
            }
            else {
                front++;
            }
            return deletedElement;
        }
    }
};

// Class to represent a graph using adjacency list
class Graph {
private:
    int n;  // Number of vertices
    Node* adj[MAX];  // Array of linked lists to store the adjacency list

public:
    Graph() {
        n = 0;
        for (int i = 0; i < MAX; i++) {
            adj[i] = nullptr;
        }
    }

    Graph(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            adj[i] = nullptr;
        }
    }

    // Add an edge to the graph (undirected)
    void addEdge(int u, int v) {
        Node* newNode = new Node(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = new Node(u);  // Since it's undirected, add reverse edge
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // Remove an edge between u and v (undirected graph)
    void removeEdge(int u, int v) {
        Node* temp = adj[u], * prev = nullptr;
        while (temp != nullptr && temp->vertex != v) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr) {  // Edge found
            if (prev == nullptr) {  // Removing the first node
                adj[u] = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
        }

        // Remove the edge from the other side as well (since undirected)
        temp = adj[v], prev = nullptr;
        while (temp != nullptr && temp->vertex != u) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr) {  // Edge found
            if (prev == nullptr) {  // Removing the first node
                adj[v] = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
        }
    }

    // Remove a vertex and all edges associated with it
    void removeVertex(int v) {
        // Remove edges to the vertex v from all adjacency lists
        for (int i = 0; i < n; i++) {
            removeEdge(i, v);
        }

        // Remove the vertex v from the adjacency list
        adj[v] = nullptr;
    }

    // Insert a vertex into the graph
    void insertVertex() {
        if (n >= MAX) {
            cout << "Maximum vertex limit reached.\n";
            return;
        }
        adj[n] = nullptr;
        n++;
        cout << "Vertex " << n - 1 << " added.\n";
    }

    // Check if the graph is empty
    bool isEmpty() {
        for (int i = 0; i < n; i++) {
            if (adj[i] != nullptr) {
                return false;
            }
        }
        return true;
    }

    // DFS function to visit nodes
    void DFS(int v, bool visited[]) {
        visited[v] = true; // Mark current vertex as visited
        cout << "Visited " << v << endl;

        // Visit all the adjacent vertices of v
        Node* temp = adj[v];
        while (temp != nullptr) {
            int w = temp->vertex;
            if (!visited[w]) {
                DFS(w, visited);
            }
            temp = temp->next;
        }
    }

    // Perform Depth First Search starting from vertex 0
    void DepthFirstSearch() {
        bool visited[MAX] = { false }; // Array to track visited vertices

        // Visit each vertex if it's not already visited
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, visited); // Perform DFS from this unvisited vertex
            }
        }
    }

    // BFS function to perform breadth-first search
    void BFS(int v) {
        bool visited[MAX] = { false }; // Array to track visited vertices
        Queue q;  // Create a queue to manage vertices to be explored

        visited[v] = true;  // Mark the starting vertex as visited
        cout << "Visited " << v << endl;
        q.insert(v);  // Add the starting vertex to the queue

        while (!q.IsEmpty()) {
            int current = q.deleteElement();  // Get the front vertex from the queue

            // Explore all adjacent vertices of the current vertex
            Node* temp = adj[current];
            while (temp != nullptr) {
                int w = temp->vertex;
                if (!visited[w]) {
                    cout << "Visited " << w << endl;  // Visit the vertex
                    visited[w] = true;  // Mark the vertex as visited
                    q.insert(w);  // Add the vertex to the queue
                }
                temp = temp->next;
            }
        }
    }

    // Display the adjacency list
    void displayGraph() {
        cout << "Adjacency List of the Graph:\n";
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << ": ";
            Node* temp = adj[i];
            while (temp != nullptr) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, u, v;
    string choice;

    // Input the number of vertices
    cout << "Enter the number of vertices in the graph: ";
    while (!(cin >> vertices) || vertices <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    Graph g(vertices);  // Create the graph with the given number of vertices

    while (true) {
        // Menu-based interface
        cout << "\nMenu:\n";
        cout << "1. Insert an edge\n";
        cout << "2. Insert a vertex\n";
        cout << "3. Remove an edge\n";
        cout << "4. Remove a vertex\n";
        cout << "5. Perform Depth First Search\n";
        cout << "6. Perform Breadth First Search\n";
        cout << "7. Display graph (Adjacency List)\n";
        cout << "8. Check if graph is empty\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        getline(cin, choice);  // Get the choice as a string

        if (choice == "1") {
            cout << "Enter the two vertices to add an edge between (0 to " << vertices - 1 << "): ";
            while (!(cin >> u >> v)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();  // Consume the newline character after reading u and v
            if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
                g.addEdge(u, v);  // Add an edge between u and v
                cout << "Edge added between " << u << " and " << v << endl;
            }
            else {
                cout << "Invalid vertices!\n";
            }
        }
        else if (choice == "2") {
            g.insertVertex();  // Insert a vertex into the graph
            vertices++;  // Increase the vertex count when a vertex is added
        }
        else if (choice == "3") {
            cout << "Enter the two vertices to remove an edge between (0 to " << vertices - 1 << "): ";
            while (!(cin >> u >> v)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();
            g.removeEdge(u, v);
            cout << "Edge removed between " << u << " and " << v << endl;
        }
        else if (choice == "4") {
            cout << "Enter the vertex to remove: ";
            while (!(cin >> v)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();
            g.removeVertex(v);
            cout << "Vertex " << v << " removed.\n";
        }
        else if (choice == "5") {
            cout << "Performing Depth First Search (DFS):\n";
            g.DepthFirstSearch();  // Perform DFS starting from vertex 0
        }
        else if (choice == "6") {
            cout << "Enter the starting vertex for BFS: ";
            while (!(cin >> v)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();
            if (v >= 0 && v < vertices) {
                cout << "Performing Breadth First Search (BFS):\n";
                g.BFS(v);  // Perform BFS starting from the provided vertex
            }
            else {
                cout << "Invalid vertex!\n";
            }
        }
        else if (choice == "7") {
            g.displayGraph();  // Display adjacency list
        }
        else if (choice == "8") {
            if (g.isEmpty()) {
                cout << "The graph is empty.\n";
            }
            else {
                cout << "The graph is not empty.\n";
            }
        }
        else if (choice == "9") {
            cout << "Exiting...\n";
            return 0;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

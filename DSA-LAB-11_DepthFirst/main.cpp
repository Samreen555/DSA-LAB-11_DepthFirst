//#include <iostream>
//#define Elements 50
//using namespace std;
//// Structure to represent a vertex
//struct vertex
//{
//    string info; // Information associated with each vertex
//};
//
//// Structure to represent an edge (for unweighted graph)
//struct edge
//{
//    int adj; // 0 or 1 indicating if an edge exists
//};
//
//// Structure to represent a weighted edge
//struct weighted_edge
//{
//    int adj;    // 0 or 1 indicating if an edge exists
//    int weight; // Weight of the edge
//};
//
//// Class for Graph (unweighted graph)
//class Graph
//{
//private:
//    vertex vertices[Elements];       // Array of vertices
//    edge edges[Elements][Elements];       // Adjacency matrix for edges
//    int adj[Elements][Elements] = { 0 };    // Simple adjacency matrix
//
//public:
//    Graph() {} // Default Constructor
//
//    // Function to add an edge (unweighted graph)
//    void join(int vertex1, int vertex2)
//    {
//        if (vertex1 < Elements && vertex2 < Elements)
//        {
//            adj[vertex1][vertex2] = 1;
//            cout << "Edge added between " << vertex1 << " and " << vertex2 << ".\n";
//        }
//    }
//
//    // Function to remove an edge
//    void remove(int vertex1, int vertex2)
//    {
//        if (vertex1 < Elements && vertex2 < Elements)
//        {
//            adj[vertex1][vertex2] = 0;
//            cout << "Edge removed between " << vertex1 << " and " << vertex2 << ".\n";
//        }
//    }
//
//    // Function to check if two vertices are adjacent
//    bool adjacent(int vertex1, int vertex2)
//    {
//        if (vertex1 < Elements && vertex2 < Elements)
//            return adj[vertex1][vertex2] == 1;
//        return false;
//    }
//
//    // Function to display adjacency matrix
//    void display()
//    {
//        cout << "Adjacency Matrix:\n";
//        for (int i = 0; i < Elements; ++i)
//        {
//            for (int j = 0; j < Elements; ++j)
//                cout << adj[i][j] << " ";
//            cout << endl;
//        }
//    }
//};
//
//// Class for Weighted Graph
//class WeightedGraph
//{
//private:
//    weighted_edge g[Elements][Elements]; // Adjacency matrix for weighted edges
//
//public:
//    WeightedGraph()
//    {
//        // Initialize the adjacency matrix
//        for (int i = 0; i < Elements; ++i)
//        {
//            for (int j = 0; j < Elements; ++j)
//            {
//                g[i][j].adj = 0;
//                g[i][j].weight = 0;
//            }
//        }
//    }
//
//    // Function to add a weighted edge
//    void joinwt(int vertex1, int vertex2, int wt)
//    {
//        if (vertex1 < Elements && vertex2 < Elements)
//        {
//            g[vertex1][vertex2].adj = 1;
//            g[vertex1][vertex2].weight = wt;
//            cout << "Weighted edge added between " << vertex1 << " and " << vertex2
//                << " with weight " << wt << ".\n";
//        }
//    }
//
//    // Function to remove a weighted edge
//    void remvwt(int vertex1, int vertex2)
//    {
//        if (vertex1 < Elements && vertex2 < Elements)
//        {
//            g[vertex1][vertex2].adj = 0;
//            g[vertex1][vertex2].weight = 0;
//            cout << "Weighted edge removed between " << vertex1 << " and " << vertex2 << ".\n";
//        }
//    }
//
//    // Function to check if two vertices are adjacent
//    bool adjacent(int vertex1, int vertex2)
//    {
//        if (vertex1 < Elements && vertex2 < Elements)
//            return g[vertex1][vertex2].adj == 1;
//        return false;
//    }
//
//    // Function to display the weighted adjacency matrix
//    void display()
//    {
//        cout << "Weighted Adjacency Matrix:\n";
//        for (int i = 0; i < Elements; ++i)
//        {
//            for (int j = 0; j < Elements; ++j)
//            {
//                if (g[i][j].adj == 1)
//                    cout << g[i][j].weight << " ";
//                else
//                    cout << "0 ";
//            }
//            cout << endl;
//        }
//    }
//};
//
//// Main function for testing
//int main()
//{
//    Graph unweightedGraph;
//    WeightedGraph weightedGraph;
//
//    // Unweighted Graph Test
//    cout << "Unweighted Graph Operations:\n";
//    unweightedGraph.join(0, 1);
//    unweightedGraph.join(0, 2);
//    unweightedGraph.remove(0, 1);
//    cout << "Are 0 and 2 adjacent? " << (unweightedGraph.adjacent(0, 2) ? "Yes" : "No") << endl;
//    unweightedGraph.display();
//
//    // Weighted Graph Test
//    cout << "\nWeighted Graph Operations:\n";
//    weightedGraph.joinwt(0, 1, 10);
//    weightedGraph.joinwt(0, 2, 20);
//    weightedGraph.remvwt(0, 1);
//    cout << "Are 0 and 2 adjacent? " << (weightedGraph.adjacent(0, 2) ? "Yes" : "No") << endl;
//    weightedGraph.display();
//
//    return 0;
//}

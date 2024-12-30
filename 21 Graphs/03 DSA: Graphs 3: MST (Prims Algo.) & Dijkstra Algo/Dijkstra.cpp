// // https://www.scaler.com/academy/mentee-dashboard/class/297873/assignment/problems/4706?navref=cl_tt_lst_sl

// // https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/

// // Problem Description

// // Given a weighted undirected graph having A nodes and M weighted edges, and a source node C.

// // You have to find an integer array D of size A such that:

// // D[i]: Shortest distance from the C node to node i.
// // If node i is not reachable from C then -1.
// // Note:

// // There are no self-loops in the graph.
// // There are no multiple edges between two pairs of vertices.
// // The graph may or may not be connected.
// // Nodes are numbered from 0 to A-1.
// // Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.



// // Problem Constraints

// // 1 <= A <= 1e5

// // 0 <= B[i][0],B[i][1] < A

// // 0 <= B[i][2] <= 1e3

// // 0 <= C < A



// // Input Format

// // The first argument is an integer A, representing the number of nodes in the graph.
// // The second argument is a matrix B of size M x 3, where each row represents an edge in the graph. The three columns of each row denote the source node B[i][0], the destination node B[i][1], and the weight of the edge B[i][2].
// // The third argument is an integer C, representing the source node for which the shortest distance to all other nodes needs to be found.


// // Output Format

// // Return the integer array D.



// // Example Input

// // Input 1:

// // A = 6
// // B = [   [0, 4, 9]
// //         [3, 4, 6] 
// //         [1, 2, 1] 
// //         [2, 5, 1] 
// //         [2, 4, 5] 
// //         [0, 3, 7] 
// //         [0, 1, 1] 
// //         [4, 5, 7] 
// //         [0, 5, 1] ] 
// // C = 4
// // Input 2:

// // A = 5
// // B = [   [0, 3, 4]
// //         [2, 3, 3] 
// //         [0, 1, 9] 
// //         [3, 4, 10] 
// //         [1, 3, 8]  ] 
// // C = 4


// // Example Output

// // Output 1:

// // D = [7, 6, 5, 6, 0, 6]
// // Output 2:

// // D = [14, 18, 13, 10, 0]


// // Example Explanation

// // Explanation 1:

// //  All Paths can be considered from the node C to get shortest path
// // Explanation 2:

// //  All Paths can be considered from the node C to get shortest path


// Following are the detailed steps. 

// Create a Min Heap of size V where V is the number of vertices in the given graph. Every node of the min-heap contains the vertex number and distance value of the vertex. 
// Initialize Min Heap with source vertex as root (the distance value assigned to source vertex is 0). The distance value assigned to all other vertices is INF (infinite). 
// While Min Heap is not empty, do the following :
// Extract the vertex with minimum distance value node from Min Heap. Let the extracted vertex be u. 
// For every adjacent vertex v of u, check if v is in Min Heap. If v is in Min Heap and the distance value is more than the weight of u-v plus the distance value of u, then update the distance value of v.

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solve(int A, vector<vector<int> > &B, int C) {
    vector<vector<pair<int, int>>> adj(A);
    for (auto& edge : B) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }


    vector<int> distance(A, INT_MAX);
    distance[C] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
    pq.push({0, C}); // distance, node

    while (!pq.empty()) {
        auto [currentDist, node] = pq.top();
        pq.pop();

        if (currentDist > distance[node]) continue;

        for (auto& [neighbor, weight] : adj[node]) {
            int newDist = currentDist + weight;
            if (newDist < distance[neighbor]) {
                distance[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }

    for (int i = 0; i < A; i++) {
        if (distance[i] == INT_MAX) distance[i] = -1;
    }

    return distance;
}

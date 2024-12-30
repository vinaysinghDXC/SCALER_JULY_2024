// https://www.scaler.com/academy/mentee-dashboard/class/297909/assignment/problems/4707?navref=cl_tt_lst_sl

// Problem Description

// Given a weighted undirected graph having A nodes, a source node C and destination node D.

// Find the shortest distance from C to D and if it is impossible to reach node D from C then return -1.

// You are expected to do it in Time Complexity of O(A + M).

// Note:

// There are no self-loops in the graph.

// No multiple edges between two pair of vertices.

// The graph may or may not be connected.

// Nodes are Numbered from 0 to A-1.

// Your solution will run on multiple testcases. If you are using global variables make sure to clear them.



// Problem Constraints

// 1 <= A <= 105

// 0 <= B[i][0], B[i][1] < A

// 1 <= B[i][2] <= 2

// 0 <= C < A

// 0 <= D < A



// Input Format

// The first argument given is an integer A, representing the number of nodes.

// The second argument given is the matrix B, where B[i][0] and B[i][1] are connected through an edge of weight B[i][2].

// The third argument given is an integer C, representing the source node.

// The fourth argument is an integer D, representing the destination node.

// Note: B[i][2] will be either 1 or 2.



// Output Format

// Return the shortest distance from C to D. If it is impossible to reach node D from C then return -1.



// Example Input

// Input 1:

 
// A = 6
// B = [   [2, 5, 1]
//         [1, 3, 1] 
//         [0, 5, 2] 
//         [0, 2, 2] 
//         [1, 4, 1] 
//         [0, 1, 1] ] 
// C = 3
// D = 2
// Input 2:

// A = 2
// B = [   [0, 1, 1]
//     ] 
// C = 0
// D = 1


// Example Output

// Output 1:

//  4
// Output 2:

//  1


// Example Explanation

// Explanation 1:

// The path to be followed will be:
//     3 -> 1 (Edge weight : 1)
//     1 -> 0 (Edge weight : 1)
//     0 -> 2 (Edge weight : 2)
// Total length of path = 1 + 1 + 2 = 4.
// Explanation 2:

//  Path will be 0-> 1.

#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solve(int A, vector<vector<int> > &B, int C, int D) {
    vector<vector<pair<int, int> > > adj(A); // {neighbor, weight}
    for (auto &edge : B) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(A, INT_MAX);
    deque<int> dq;
    dist[C] = 0;
    dq.push_front(C);

    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for (auto &neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (dist[node] + weight < dist[nextNode]) {
                dist[nextNode] = dist[node] + weight;
                if (weight == 1) {
                    dq.push_front(nextNode); //push to the front
                } else {
                    dq.push_back(nextNode); //push to the back
                }
            }
        }
    }

    return dist[D] == INT_MAX ? -1 : dist[D];
}

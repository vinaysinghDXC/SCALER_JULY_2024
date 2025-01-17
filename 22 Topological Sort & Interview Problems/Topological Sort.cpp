// https://www.scaler.com/academy/mentee-dashboard/class/297857/assignment/problems/9328/?navref=cl_pb_nv_tb

// Problem Description

// Given an directed acyclic graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

// Return the topological ordering of the graph and if it doesn't exist then return an empty array.

// If there is a solution return the correct ordering. If there are multiple solutions print the lexographically smallest one.

// Ordering (a, b, c) is said to be lexographically smaller than ordering (e, f, g) if a < e or if(a==e) then b < f and so on.

// NOTE:

// There are no self-loops in the graph.
// The graph may or may not be connected.
// Nodes are numbered from 1 to A.
// Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


// Problem Constraints

// 2 <= A <= 104

// 1 <= M <= min(100000,A*(A-1))

// 1 <= B[i][0], B[i][1] <= A



// Input Format

// The first argument given is an integer A representing the number of nodes in the graph.

// The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].



// Output Format

// Return a one-dimensional array denoting the topological ordering of the graph and it it doesn't exist then return empty array.



// Example Input

// Input 1:

//  A = 6
//  B = [  [6, 3] 
//         [6, 1] 
//         [5, 1] 
//         [5, 2] 
//         [3, 4] 
//         [4, 2] ]
// Input 2:

//  A = 3
//  B = [  [1, 2]
//         [2, 3] 
//         [3, 1] ]


// Example Output

// Output 1:

//  [5, 6, 1, 3, 4, 2]
// Output 2:

//  []


// Example Explanation

// Explanation 1:

//  The given graph contain no cycle so topological ordering exists which is [5, 6, 1, 3, 4, 2]
// Explanation 2:

//  The given graph contain cycle so topological ordering not possible we will return empty array.

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solve(int A, vector<vector<int> > &B) {
    vector<int> toporder;
    int n = B.size();

    vector<int> incoming(A + 1, 0);
    vector<vector<int> > adj(A + 1);
    
    for (int i = 0; i < n; i++) {
        int u = B[i][0], v = B[i][1];
        adj[u].push_back(v);
        incoming[v]++;
    }

    priority_queue<int, vector<int>, greater<int> > q;
    
    for (int i = 1; i <= A; i++) {
        if (incoming[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int r = q.top();
        q.pop();
        toporder.push_back(r);

        for (int neighbor : adj[r]) {
            incoming[neighbor]--;
            if (incoming[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (toporder.size() != A) {
        return {};
    }

    return toporder;
}

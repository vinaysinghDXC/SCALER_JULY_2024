// https://www.scaler.com/academy/mentee-dashboard/class/297901/assignment/problems/9327?navref=cl_tt_nv

// Problem Description

// Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

// Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

// NOTE:

// The cycle must contain atleast two nodes.
// There are no self-loops in the graph.
// There are no multiple edges between two nodes.
// The graph may or may not be connected.
// Nodes are numbered from 1 to A.
// Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


// Problem Constraints

// 2 <= A <= 105

// 1 <= M <= min(200000,A*(A-1))

// 1 <= B[i][0], B[i][1] <= A



// Input Format

// The first argument given is an integer A representing the number of nodes in the graph.

// The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].



// Output Format

// Return 1 if cycle is present else return 0.



// Example Input

// Input 1:

//  A = 5
//  B = [  [1, 2] 
//         [4, 1] 
//         [2, 4] 
//         [3, 4] 
//         [5, 2] 
//         [1, 3] ]
// Input 2:

//  A = 5
//  B = [  [1, 2]
//         [2, 3] 
//         [3, 4] 
//         [4, 5] ]


// Example Output

// Output 1:

//  1
// Output 2:

//  0


// Example Explanation

// Explanation 1:

//  The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1
// Explanation 2:

//  The given graph doesn't contain any cycle.


#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int> > &adj, vector<bool> &visited, vector<bool> &currpath, int idx){
    visited[idx]=true;
    currpath[idx]=true;
    for (int i = 0; i<adj[idx].size(); i++){
        int neighbor = adj[idx][i];
        if (currpath[neighbor]==true) return true;
        if (visited[neighbor]==false){
            if (dfs(adj, visited, currpath, neighbor)==true) return true;
        }
    }
    currpath[idx]=false;
    return false;
}

int solve(int A, vector<vector<int> > &B) {
    vector<vector<int> > adj(A);
    for (int i = 0; i < B.size(); i++) {
        int u = B[i][0] - 1;
        int v = B[i][1] - 1;
        adj[u].push_back(v);
    }

    vector<bool> visited(A, 0);
    vector<bool> currpath(A, 0);

    for (int i = 0; i<A; i++){
        if (visited[i]==false){
            if (dfs(adj, visited, currpath, i)==true) return 1;
        }
    }
    return 0;
}

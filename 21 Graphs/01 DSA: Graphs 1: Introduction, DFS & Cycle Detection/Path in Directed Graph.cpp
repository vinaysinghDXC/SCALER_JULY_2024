// https://www.scaler.com/academy/mentee-dashboard/class/297901/assignment/problems/9359?navref=cl_tt_lst_sl

// Problem Description

// Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size M x 2such that there is a edge directed from node

// B[i][0] to node B[i][1].

// Find whether a path exists from node 1 to node A.

// Return 1 if path exists else return 0.

// NOTE:

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

// Return 1 if path exists between node 1 to node A else return 0.



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

//  0
// Output 2:

//  1


// Example Explanation

// Explanation 1:

//  The given doens't contain any path from node 1 to node 5 so we will return 0.
// Explanation 2:

//  Path from node1 to node 5 is ( 1 -> 2 -> 3 -> 4 -> 5 ) so we will return 1.

#include <iostream>
#include <vector>

using namespace std;

int solve(int A, vector<vector<int> > &B) {
    for (int i=0; i<B.size(); i++){
        if (B[i][1]==A) return 1;
    }
    return 0;
}
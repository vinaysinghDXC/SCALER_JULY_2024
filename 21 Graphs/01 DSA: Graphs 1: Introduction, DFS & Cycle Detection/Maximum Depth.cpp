// Problem Description

// Given a Tree of A nodes having A-1 edges. Each node is numbered from 1 to A where 1 is the root of the tree.

// You are given Q queries. In each query, you will be given two integers L and X. Find the value of such node which lies at level L mod (MaxDepth + 1) and has value greater than or equal to X.

// Answer to the query is the smallest possible value or -1, if all the values at the required level are smaller than X.

// NOTE:

// Level and Depth of the root is considered as 0.
// It is guaranteed that each edge will be connecting exactly two different nodes of the tree.
// Please read the input format for more clarification.


// Problem Constraints

// 2 <= A, Q(size of array E and F) <= 105

// 1 <= B[i], C[i] <= A

// 1 <= D[i], E[i], F[i] <= 106



// Input Format

// The first argument is an integer A denoting the number of nodes.

// The second and third arguments are the integer arrays B and C where for each i (0 <= i < A-1), B[i] and C[i] are the nodes connected by an edge.

// The fourth argument is an integer array D, where D[i] denotes the value of the (i+1)th node

// The fifth and sixth arguments are the integer arrays E and F where for each i (0 <= i < Q), E[i] denotes L and F[i] denotes X for ith query.



// Output Format

// Return an array of integers where the ith element denotes the answer to ith query.



// Example Input

// Input 1:

//  A = 5
//  B = [1, 4, 3, 1]
//  C = [5, 2, 4, 4]
//  D = [7, 38, 27, 37, 1]
//  E = [1, 1, 2]
//  F = [32, 18, 26]
// Input 2:

//  A = 3
//  B = [1, 2]
//  C = [3, 1]
//  D = [7, 15, 27]
//  E = [1, 10, 1]
//  F = [29, 6, 26]


// Example Output

// Output 1:

//  [37, 37, 27]
// Output 2:

//  [-1, 7, 27]


// Example Explanation

// Explanation 1:

//       1[7]
//      /    \
//    5[1]  4[37]
//         /    \
//        2[38]  3[27]

//  Query 1: 
//     L = 1, X = 32
//     Nodes for level 1 are 5, 4
//     Value of Node 5 = 1 < 32
//     Value of Node 4 = 37 >= 32
//     Ans = 37
// Explanation 2:

//       1[7]
//      /    \
//    2[15]  3[27]

//  Query 1: 
//     L = 1, X = 6
//     Nodes for level 1 are 2, 3 having value 15 and 27 respectively.
//     Answer = -1 (Since no node is greater or equal to 29).
//  Query 1: 
//     L = 10 % 2 = 0, X = 6
//     Nodes for level 0 is 1 having value 7.
//     Answer = 7.


#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(int node, int level, vector<vector<int> >& tree, vector<int>& node_values, vector<vector<int>>& levels, vector<bool>& visited) {
    visited[node] = true;
    levels[level].push_back(node_values[node - 1]);
    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, level + 1, tree, node_values, levels, visited);
        }
    }
}

vector<int> solve(int A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E, vector<int> &F) {
    vector<vector<int> > tree(A + 1);
    for (int i = 0; i < A - 1; i++) {
        tree[B[i]].push_back(C[i]);
        tree[C[i]].push_back(B[i]);
    }

    vector<vector<int> > levels(A + 1);
    vector<bool> visited(A + 1, false);
    dfs(1, 0, tree, D, levels, visited); // starting from node 1 which is level 0

    for (auto& level : levels) {
        sort(level.begin(), level.end());
    }

    vector<int> result;
    int max_depth = 0;
    for (int i = 0; i < A + 1; i++) {
        if (!levels[i].empty()) {
            max_depth = i;
        }
    }

    for (int i = 0; i < E.size(); i++) {
        int L = E[i] % (max_depth + 1);
        int X = F[i];
        auto it = lower_bound(levels[L].begin(), levels[L].end(), X);
        if (it == levels[L].end()) {
            result.push_back(-1);
        } else {
            result.push_back(*it);
        }
    }

    return result;
}


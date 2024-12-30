// https://www.scaler.com/academy/mentee-dashboard/class/297857/homework/problems/369?navref=cl_tt_lst_sl

// Problem Description

// Find largest distance Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes.

// The goal of the problem is to find largest distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

// The nodes will be numbered 0 through N - 1.

// The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.



// Problem Constraints

// 2 <= |A| <= 40000



// Input Format

// First and only argument is vector A



// Output Format

// Return the length of the longest path



// Example Input

// Input 1:

 
// A = [-1, 0]
// Input 2:

 
// A = [-1, 0, 0]


// Example Output

// Output 1:

//  1
// Output 2:

//  2


// Example Explanation

// Explanation 1:

//  Path is 0 -> 1.
// Explanation 2:

//  Path is 1 -> 0 -> 2.


// To find the largest distance (diameter) in an unweighted tree, you can use the double BFS/DFS technique. This involves the following steps:

// Identify the root node: The root is identified as the node i for which A[i] = -1.

// First DFS/BFS:

// Start from the root (or any node if the root isn't specified).
// Find the farthest node from the starting node. This is one endpoint of the diameter.
// Second DFS/BFS:

// Start from the farthest node found in step 2.
// Find the farthest node from this starting node. The distance between these two nodes is the diameter of the tree.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Helper function to perform BFS and find the farthest node and its distance
pair<int, int> bfs(int start, const vector<vector<int> >& adj) {
    int n = adj.size();
    vector<int> distance(n, -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    int farthestNode = start, maxDistance = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (distance[neighbor] == -1) { // Not visited
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);

                if (distance[neighbor] > maxDistance) {
                    maxDistance = distance[neighbor];
                    farthestNode = neighbor;
                }
            }
        }
    }

    return {farthestNode, maxDistance};
}

int findLargestDistance(const vector<int>& A) {
    int n = A.size();
    vector<vector<int>> adj(n);

    // Build adjacency list
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] == -1) {
            root = i; // Identify the root node
        } else {
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }

    // Perform the first BFS from the root
    pair<int, int> firstBFS = bfs(root, adj);

    // Perform the second BFS from the farthest node found in the first BFS
    pair<int, int> secondBFS = bfs(firstBFS.first, adj);

    // The largest distance is the result of the second BFS
    return secondBFS.second;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << findLargestDistance(A) << endl;
    return 0;
}

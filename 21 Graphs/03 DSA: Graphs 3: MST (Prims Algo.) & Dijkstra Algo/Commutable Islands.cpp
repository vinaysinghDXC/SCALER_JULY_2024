// https://www.scaler.com/academy/mentee-dashboard/class/297873/assignment/problems/376?navref=cl_tt_lst_sl

// Problem Description

// There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

// We need to find bridges with minimal cost such that all islands are connected.

// It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.



// Problem Constraints

// 1 <= A, M <= 6*104

// 1 <= B[i][0], B[i][1] <= A

// 1 <= B[i][2] <= 103



// Input Format

// The first argument contains an integer, A, representing the number of islands.

// The second argument contains an 2-d integer matrix, B, of size M x 3 where Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].



// Output Format

// Return an integer representing the minimal cost required.



// Example Input

// Input 1:

//  A = 4
//  B = [  [1, 2, 1]
//         [2, 3, 4]
//         [1, 4, 3]
//         [4, 3, 2]
//         [1, 3, 10]  ]
// Input 2:

//  A = 4
//  B = [  [1, 2, 1]
//         [2, 3, 2]
//         [3, 4, 4]
//         [1, 4, 3]   ]


// Example Output

// Output 1:

//  6
// Output 2:

//  6


// Example Explanation

// Explanation 1:

//  We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.
// Explanation 2:

//  We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.


//---------REFERENCE--------//
// https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solve(int A, vector<vector<int> > &B) {
    vector<vector<pair<int, int>>> adj(A);

    int E = B.size();
    
    for (int i = 0; i < E; i++) {
        int u = B[i][0] - 1;
        int v = B[i][1] - 1;
        int wt = B[i][2];

        // if (u < 0 || u >= A || v < 0 || v >= A) {
        //     return -1;
        // }

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(A, false);

    int res = 0;
    int visited_count = 0;

    visited[0] = true;
    visited_count++;

    for (auto nb : adj[0]) {
        pq.push({nb.second, nb.first}); // {weight, node}
    }

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if (visited[u]) {
            continue;
        }

        res += wt;
        visited[u] = true;
        visited_count++;

        for (auto v : adj[u]) {
            if (!visited[v.first]) {
                pq.push({v.second, v.first});
            }
        }
    }

    return visited_count!=A ? -1:res;
    // if (visited_count != A) {
    //     return -1; //graph is disconnected
    // }
}


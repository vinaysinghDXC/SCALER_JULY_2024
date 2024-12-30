// https://www.scaler.com/academy/mentee-dashboard/class/297909/assignment/problems/4704/?navref=cl_pb_nv_tb

// Problem Description

// Given a matrix of integers A of size N x M consisting of 0, 1 or 2.

// Each cell can have three values:

// The value 0 representing an empty cell.

// The value 1 representing a fresh orange.

// The value 2 representing a rotten orange.

// Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1 instead.

// Note: Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.



// Problem Constraints

// 1 <= N, M <= 1000

// 0 <= A[i][j] <= 2



// Input Format

// The first argument given is the integer matrix A.



// Output Format

// Return the minimum number of minutes that must elapse until no cell has a fresh orange.

// If this is impossible, return -1 instead.



// Example Input

// Input 1:


// A = [   [2, 1, 1]
//         [1, 1, 0]
//         [0, 1, 1]   ]


// Input 2:


 
// A = [   [2, 1, 1]
//         [0, 1, 1]
//         [1, 0, 1]   ]








// Example Output

// Output 1:

//  4
// Output 2:

//  -1


// Example Explanation

// Explanation 1:

// Minute 0: [ [2, 1, 1]
//             [1, 1, 0]
//             [0, 1, 1] ]
// Minute 1: [ [2, 2, 1]
//             [2, 1, 0]
//             [0, 1, 1] ]
// Minute 2: [ [2, 2, 2]
//             [2, 2, 0]
//             [0, 1, 1] ]
// Minute 3: [ [2, 2, 2]
//             [2, 2, 0]
//             [0, 2, 1] ]
// Minute 4: [ [2, 2, 2]
//             [2, 2, 0]
//             [0, 2, 2] ]
// At Minute 4, all the oranges are rotten.
// Explanation 2:

// The fresh orange at 2nd row and 0th column cannot be rotten, So return -1.
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solve(vector<vector<int> > &A) {
    queue<pair<int, int> > q;

    int rows = A.size();
    int cols = A[0].size();

    int freshorange=0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == 2) {
                q.push({i, j});
            }
            if (A[i][j] == 1) freshorange++;
        }
    }

    int time = 0;

    vector<int> di = {-1, 1, 0, 0};
    vector<int> dj = {0, 0, -1, 1};

    while (!q.empty()) {
        int sz = q.size();
        bool freshRotten = false;

        for (int s = 0; s < sz; s++) {
            auto curr_idx = q.front();
            q.pop();

            int i = curr_idx.first;
            int j = curr_idx.second;

            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];

                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && A[ni][nj] == 1) {
                    q.push({ni, nj});
                    A[ni][nj] = 2;
                    freshRotten = true;
                    freshorange--;
                }
            }
        }

        if (freshRotten) {
            time++;
        }
    }

    if (freshorange>0) return-1;

    return time;
}

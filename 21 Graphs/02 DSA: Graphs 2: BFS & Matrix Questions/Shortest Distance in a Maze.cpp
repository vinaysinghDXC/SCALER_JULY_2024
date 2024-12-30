// https://www.scaler.com/academy/mentee-dashboard/class/297909/assignment/problems/4697/submissions

// Problem Description

// Given a matrix of integers A of size N x M describing a maze. The maze consists of empty locations and walls.

// 1 represents a wall in a matrix and 0 represents an empty location in a wall.

// There is a ball trapped in a maze. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall (maze boundary is also considered as a wall). When the ball stops, it could choose the next direction.

// Given two array of integers of size B and C of size 2 denoting the starting and destination position of the ball.

// Find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the starting position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.



// Problem Constraints

// 2 <= N, M <= 100

// 0 <= A[i] <= 1

// 0 <= B[i][0], C[i][0] < N

// 0 <= B[i][1], C[i][1] < M



// Input Format

// The first argument given is the integer matrix A.

// The second argument given is an array of integer B.

// The third argument if an array of integer C.



// Output Format

// Return a single integer, the minimum distance required to reach destination



// Example Input

// Input 1:


// A = [ [0, 0], 
//       [0, 0] ]
// B = [0, 0]
// C = [0, 1]


// Input 2:

// A = [ [0, 1], 
//       [1, 0] ]
// B = [0, 0]
// C = [1, 1]












// Example Output

// Output 1:


//  1


// Output 2:

//  -1












// Example Explanation

// Explanation 1:

//  Go directly from start to destination in distance 1.
// Explanation 2:

//  It is impossible to reach the destination from (0, 0) to (1, 1) as there are walls at (1, 0) and (0, 1)

#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    vector<vector<int> > distance(A.size(), vector<int>(A[0].size(), INT_MAX));
    distance[B[0]][B[1]] = 0;

    queue<pair<int, int> > q;
    q.push({B[0], B[1]});

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    while (!q.empty()) {
        auto rp = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = rp.first, nj = rp.second;
            int count = 0;

            while ((ni+dx[k]) >= 0 && (ni+dx[k]) < A.size() && nj+dy[k] >= 0 && nj+dy[k] < A[0].size() && A[ni+dx[k]][nj+dy[k]] == 0) {
                ni += dx[k];
                nj += dy[k];
                count++;
            }

            int newdist = distance[rp.first][rp.second] + count;

            if (newdist < distance[ni][nj]) {
                distance[ni][nj] = newdist;
                q.push({ni, nj});
            }
        }
    }

    return distance[C[0]][C[1]] == INT_MAX ? -1 : distance[C[0]][C[1]];
}

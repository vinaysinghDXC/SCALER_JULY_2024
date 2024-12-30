// https://www.scaler.com/academy/mentee-dashboard/class/297909/assignment/problems/4702/submissions

// Problem Description

// Given a matrix of integers A of size N x M consisting of 0 and 1. A group of connected 1's forms an island. From a cell (i, j) such that A[i][j] = 1 you can visit any cell that shares a corner with (i, j) and value in that cell is 1.

// More formally, from any cell (i, j) if A[i][j] = 1 you can visit:

// (i-1, j) if (i-1, j) is inside the matrix and A[i-1][j] = 1.
// (i, j-1) if (i, j-1) is inside the matrix and A[i][j-1] = 1.
// (i+1, j) if (i+1, j) is inside the matrix and A[i+1][j] = 1.
// (i, j+1) if (i, j+1) is inside the matrix and A[i][j+1] = 1.
// (i-1, j-1) if (i-1, j-1) is inside the matrix and A[i-1][j-1] = 1.
// (i+1, j+1) if (i+1, j+1) is inside the matrix and A[i+1][j+1] = 1.
// (i-1, j+1) if (i-1, j+1) is inside the matrix and A[i-1][j+1] = 1.
// (i+1, j-1) if (i+1, j-1) is inside the matrix and A[i+1][j-1] = 1.
// Return the number of islands.

// NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.



// Problem Constraints

// 1 <= N, M <= 100

// 0 <= A[i] <= 1



// Input Format

// The only argument given is the integer matrix A.



// Output Format

// Return the number of islands.



// Example Input

// Input 1:

//  A = [ 
//        [0, 1, 0]
//        [0, 0, 1]
//        [1, 0, 0]
//      ]
// Input 2:

//  A = [   
//        [1, 1, 0, 0, 0]
//        [0, 1, 0, 0, 0]
//        [1, 0, 0, 1, 1]
//        [0, 0, 0, 0, 0]
//        [1, 0, 1, 0, 1]    
//      ]


// Example Output

// Output 1:

//  2
// Output 2:

//  5


// Example Explanation

// Explanation 1:

//  The 1's at position A[0][1] and A[1][2] forms one island.
//  Other is formed by A[2][0].
// Explanation 2:

//  There 5 island in total.


#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &A, int i, int j){
    vector<int> dx = {-1, 0, 1, 0, -1, -1, 1, 1};
    vector<int> dy = {0, -1, 0, 1, -1, 1, -1, 1};
    A[i][j]=2;
    for (int k = 0; k<8; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni>=0 && ni<A.size() && nj>=0 && nj<A[0].size() && A[ni][nj]==1){
            dfs(A, ni, nj);
        }
    }
}

int solve(vector<vector<int> > &A) {
    int count = 0;
    for (int i = 0; i<A.size(); i++){
        for (int j = 0; j<A[0].size(); j++){
            if (A[i][j]==1){
                dfs(A, i, j);
                count++;
            }
        }
    }
    return count;
}

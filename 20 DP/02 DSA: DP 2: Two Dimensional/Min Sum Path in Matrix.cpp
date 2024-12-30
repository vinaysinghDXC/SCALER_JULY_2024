// https://www.scaler.com/academy/mentee-dashboard/class/297877/homework/problems/19?navref=cl_tt_lst_slhttps://www.scaler.com/academy/mentee-dashboard/class/297877/homework/problems/19?navref=cl_tt_lst_sl

// Problem Description

// Given a M x N grid A of integers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Return the minimum sum of the path.

// NOTE: You can only move either down or right at any point in time.



// Problem Constraints

// 1 <= M, N <= 2000

// -1000 <= A[i][j] <= 1000



// Input Format

// First and only argument is a 2-D grid A.



// Output Format

// Return an integer denoting the minimum sum of the path.



// Example Input

// Input 1:

//  A = [
//        [1, 3, 2]
//        [4, 3, 1]
//        [5, 6, 1]
//      ]
// Input 2:

//  A = [
//        [1, -3, 2]
//        [2, 5, 10]
//        [5, -5, 1]
//      ]


// Example Output

// Output 1:

//  8
// Output 2:

//  -1


// Example Explanation

// Explanation 1:

//  The path will be: 1 -> 3 -> 2 -> 1 -> 1.
// Input 2:

//  The path will be: 1 -> -3 -> 5 -> -5 -> 1.

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int minpath(vector<vector<int>> &A, int r, int c, vector<vector<int> > &dp) {
    if (r == 0 && c == 0) return A[r][c];
    
    if (r < 0 || c < 0) return INT_MAX;

    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = A[r][c] + min(minpath(A, r - 1, c, dp), minpath(A, r, c - 1, dp));

    return dp[r][c];
}

int minPathSum(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), -1));

    return minpath(A, A.size() - 1, A[0].size() - 1, dp);
}


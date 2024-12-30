// https://www.scaler.com/academy/mentee-dashboard/class/297877/assignment/problems/278?navref=cl_tt_lst_sl

// Problem Description

// Given a 2 x N grid of integers, A, your task is to choose numbers from the grid such that sum of these numbers is maximized. 
// However, you cannot choose two numbers that are adjacent horizontally, vertically, or diagonally. 

// Return the maximum possible sum.

// Note: You are allowed to choose more than 2 numbers from the grid.


// Problem Constraints

// 1 <= N <= 20000
// 1 <= A[i] <= 2000


// Input Format

// The first and the only argument of input contains a 2d matrix, A.


// Output Format

// Return an integer, representing the maximum possible sum.


// Example Input

// Input 1:

//  A = [   
//         [1]
//         [2]    
//      ]
// Input 2:

//  A = [   
//         [1, 2, 3, 4]
//         [2, 3, 4, 5]    
//      ]


// Example Output

// Output 1:

//  2
// Output 2:

//  8


// Example Explanation

// Explanation 1:

//  We will choose 2 (From 2nd row 1st column).
// Explanation 2:

//  We will choose 3 (From 2nd row 2nd column) and 5 (From 2nd row 4th column).

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int maxsum(vector<vector<int> > &A, int idx, vector<int> &dp){
    if (idx < 0) return 0;
    if (dp[idx]!=-1) return dp[idx];
    int f1 = 0 + maxsum(A, idx - 1, dp); //don't select the current column
    int f2 = max(A[0][idx], A[1][idx]) + maxsum(A, idx - 2, dp); //select the max row from current column
    dp[idx] = max(f1, f2);
    return dp[idx];
}

// use the skip and take concept, where we either select the cell or reject the cell
// if we reject the cell, run the recursion for the next cell
// if we accepth the cell, check which is max in the current column, and the run the recursion for the +2 cell/row

int adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> dp(n, -1);
    return maxsum(A, n-1, dp);
}

// https://www.scaler.com/academy/mentee-dashboard/class/297845/assignment/problems/9318?navref=cl_tt_lst_sl

// Problem Description

// Given a rod of length N units and an array A of size N denotes prices that contains prices of all pieces of size 1 to N.

// Find and return the maximum value that can be obtained by cutting up the rod and selling the pieces.



// Problem Constraints

// 1 <= N <= 1000

// 0 <= A[i] <= 106



// Input Format

// First and only argument is an integer array A of size N.



// Output Format

// Return an integer denoting the maximum value that can be obtained by cutting up the rod and selling the pieces.



// Example Input

// Input 1:

//  A = [3, 4, 1, 6, 2]
// Input 2:

//  A = [1, 5, 2, 5, 6]


// Example Output

// Output 1:

//  15
// Output 2:

//  11


// Example Explanation

// Explanation 1:

//  Cut the rod of length 5 into 5 rods of length (1, 1, 1, 1, 1) and sell them for (3 + 3 + 3 + 3 + 3) = 15.
// Explanation 2:

//  Cut the rod of length 5 into 3 rods of length (2, 2, 1) and sell them for (5 + 5 + 1) = 11.


int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = A[0];

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j<i; j++) {
            dp[i] = max(dp[i], A[j] + dp[i - j - 1]);
        }
    }

    return dp[n];
}

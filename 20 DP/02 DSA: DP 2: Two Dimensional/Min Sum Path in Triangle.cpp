// https://www.scaler.com/academy/mentee-dashboard/class/297877/homework/problems/25?navref=cl_tt_lst_sl

// Problem Description

// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.








// Adjacent numbers for jth column of ith row is jth and (j+1)th column of (i + 1)th row








// Problem Constraints

// |A| <= 1000

// A[i] <= 1000



// Input Format

// First and only argument is the vector of vector A defining the given triangle



// Output Format

// Return the minimum sum



// Example Input

// Input 1:

 
// A = [ 
//          [2],
//         [3, 4],
//        [6, 5, 7],
//       [4, 1, 8, 3]
//     ]
// Input 2:

//  A = [ [1] ]


// Example Output

// Output 1:

//  11
// Output 2:

//  1


// Example Explanation

// Explanation 1:

//  The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
// Explanation 2:

//  Only 2 can be collected.
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int minpath(vector<vector<int> > &A, int i, int j, vector<vector<int> > &dp){
    if (i==A.size()) return 0;
    if (dp[i][j]!=-1) return dp[i][j];

    dp[i][j] = A[i][j] + min(minpath(A, i+1, j, dp), minpath(A, i+1, j+1, dp));

    return dp[i][j];
}

int minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > dp(A.size(), vector<int> (A.size(), -1));

    return minpath(A, 0, 0, dp);
}

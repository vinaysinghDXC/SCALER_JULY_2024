// https://www.scaler.com/academy/mentee-dashboard/class/297845/homework/problems/4824/submissions

// Problem Description

// Given a strictly increasing array A of positive integers forming a sequence.

// A sequence X1, X2, X3, ..., XN is fibonacci like if


// N > =3
// Xi + Xi+1 = Xi+2 for all i+2 <= N
// Find and return the length of the longest Fibonacci-like subsequence of A.

// If one does not exist, return 0.

// NOTE: A subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.



// Problem Constraints

// 3 <= length of the array <= 1000

// 1 <= A[i] <= 109



// Input Format

// The only argument given is the integer array A.



// Output Format

// Return the length of the longest Fibonacci-like subsequence of A.
// If one does not exist, return 0.



// Example Input

// Input 1:

//  A = [1, 2, 3, 4, 5, 6, 7, 8]
// Input 2:

//  A = [1, 3, 7, 11, 12, 14, 18]


// Example Output

// Output 1:

//  5
// Output 2:

//  3


// Example Explanation

// Explanation 1:

//  The longest subsequence that is fibonacci-like: [1, 2, 3, 5, 8].
// Explanation 2:

//  The longest subsequence that is fibonacci-like: [1, 11, 12], [3, 11, 14] or [7, 11, 18].
//  The length will be 3.

#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

int solve(vector<int> &A) {
    unordered_map<int, int> map;
    int N = A.size(), res = 0;
 
    int dp[N][N];
 
    for (int j = 0; j < N; j++) {
        map[A[j]] = j;
        for (int i = 0; i < j; i++) {
            int k = map.find(A[j] - A[i]) == map.end() ? -1 : (map[A[j] - A[i]]);
 
            dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? (dp[k][i] + 1) : 2;
            res = max(res, dp[i][j]);
        }
    }
 
    return res > 2 ? res : 0;
}

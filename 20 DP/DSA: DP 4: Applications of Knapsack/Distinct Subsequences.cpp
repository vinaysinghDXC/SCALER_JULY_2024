// https://www.scaler.com/academy/mentee-dashboard/class/297845/homework/problems/7?navref=cl_tt_nv

// Problem Description

// Given two sequences A and B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

// Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).



// Problem Constraints

// 1 <= length(A), length(B) <= 700



// Input Format

// The first argument of input contains a string A.
// The second argument of input contains a string B.



// Output Format

// Return an integer representing the answer as described in the problem statement.



// Example Input

// Input 1:

//  A = "abc"
//  B = "abc"
// Input 2:

//  A = "rabbbit" 
//  B = "rabbit" 


// Example Output

// Output 1:

//  1
// Output 2:

//  3


// Example Explanation

// Explanation 1:

//  Both the strings are equal.
// Explanation 2:

//  These are the possible removals of characters:
//     => A = "ra_bbit" 
//     => A = "rab_bit" 
//     => A = "rabb_it"

//  Note: "_" marks the removed character.

//----------reference----------//
// https://takeuforward.org/data-structure/distinct-subsequences-dp-32/

#include <iostream>
#include <vector>

using namespace std;

int countseq(string A, string B, int idxA, int idxB, vector<vector<int> > &dp){
    if (idxB<0) return 1;
    if (idxA<0) return 0;

    if (dp[idxA][idxB]!=-1) return dp[idxA][idxB];

    int count = 0;
    if (A[idxA]==B[idxB]){
        count = countseq(A, B, idxA-1, idxB-1, dp) + countseq(A, B, idxA-1, idxB, dp);
    }
    else count = countseq(A, B, idxA-1, idxB, dp);

    dp[idxA][idxB]=count;

    return count;
}

int Solution::numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();

    vector<vector<int> >dp(n+1, vector<int> (m+1, -1));

    return countseq(A, B, n-1, m-1, dp);
}

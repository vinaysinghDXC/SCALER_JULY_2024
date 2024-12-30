// https://www.scaler.com/academy/mentee-dashboard/class/297845/homework/problems/1065?navref=cl_tt_lst_sl

// Problem Description

// In Danceland, one person can party either alone or can pair up with another person.

// Can you find in how many ways they can party if there are A people in Danceland?

// Note: Return your answer modulo 10003, as the answer can be large.



// Problem Constraints

// 1 <= A <= 105



// Input Format

// Given only argument A of type Integer, number of people in Danceland.



// Output Format

// Return an integer denoting the number of ways people of Danceland can party.



// Example Input

// Input 1:

//  A = 3
// Input 2:

//  A = 5


// Example Output

// Output 1:

//  4
// Output 2:

//  26


// Example Explanation

// Explanation 1:

//  Let suppose three people are A, B, and C. There are only 4 ways to party
//  (A, B, C) All party alone
//  (AB, C) A and B party together and C party alone
//  (AC, B) A and C party together and B party alone
//  (BC, A) B and C party together and A
//  here 4 % 10003 = 4, so answer is 4.
 
// Explanation 2:

//  Number of ways they can party are: 26.


// The idea is to use dynamic programming to solve this problem. There are two situations: Either the person join dance as single individual or as a pair. For the first case the problem reduces to finding the solution for p-1 people. For the second case, there are p-1 choices to select an individual for pairing and after selecting an individual for pairing the problem reduces to finding solution for p-2 people as two people among p are already paired. 
// So the formula for dp is: 
 

// dp[p] = dp[p-1] + (p-1) * dp[p-2].

#include <vector>
#include <algorithm>
using namespace std;

int solve(int A) {
    int mod= 10003;
    int count=1;

    vector<int> dp(A+1, -1);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= A; i++) {
        dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2])%mod;
    }

    return dp[A];
}



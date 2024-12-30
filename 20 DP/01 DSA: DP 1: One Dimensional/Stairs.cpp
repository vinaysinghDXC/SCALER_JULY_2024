// https://www.scaler.com/academy/mentee-dashboard/class/297861/assignment/problems/30?navref=cl_tt_lst_sl

// Problem Description

// You are climbing a staircase and it takes A steps to reach the top.


// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Return the number of distinct ways modulo 1000000007



// Problem Constraints

// 1 <= A <= 105



// Input Format

// The first and the only argument contains an integer A, the number of steps.



// Output Format

// Return an integer, representing the number of ways to reach the top.



// Example Input

// Input 1:

//  A = 2
// Input 2:

//  A = 3


// Example Output

// Output 1:

//  2
// Output 2:

//  3


// Example Explanation

// Explanation 1:

//  Distinct ways to reach top: [1, 1], [2].
// Explanation 2:

//  Distinct ways to reach top: [1 1 1], [1 2], [2 1].


// 1, 1-->1
// 2, 1,1 or 2-->2
// 3, 1,1,1 or 1, 2 or 2, 1-->3
// 4, 1,1,1,1 or 1,1,2 or 1,2,1, or 2,1,1 or 2,2-->5
// 5, 1,1,1,1,1 or 1,1,1,2 (4ways) or 1,2, 2 (3 ways) -->8

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int climbStairs(int A) {
    int mod=1000000007;
    long long ans=0;
    if (A==1) return 1;
    if (A==2) return 2;
    int a=1, b=2;
    for (int i = 3; i<=A; i++){
        ans = (a+b)%mod;
        a=b;
        b=ans;
    }

    return ans;
}

void climb(int A, int currstep, vector<int> &dp) {
    if (currstep > A) return;
    
    if (dp[currstep] != -1) return;

    int mod = 1000000007;
    
    dp[currstep] = ((currstep > 1 ? dp[currstep - 1] : 0) + (currstep > 2 ? dp[currstep - 2] : 0)) % mod;

    climb(A, currstep + 1, dp);
}

int climbStairsRecurse(int A) {
    int mod = 1000000007;
    if (A == 1) return 1;
    if (A == 2) return 2;
    
    vector<int> dp(A + 1, -1);
    dp[1] = 1;
    dp[2] = 2;
    
    climb(A, 3, dp);
    return dp[A] % mod;
}

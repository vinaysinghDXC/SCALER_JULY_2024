// https://www.scaler.com/academy/mentee-dashboard/class/297861/assignment/problems/600/submissions

// Problem Description

// Given an integer A. Return minimum count of numbers, sum of whose squares is equal to A.



// Problem Constraints

// 1 <= A <= 105



// Input Format

// First and only argument is an integer A.



// Output Format

// Return an integer denoting the minimum count.



// Example Input

// Input 1:

//  A = 6
// Input 2:

//  A = 5


// Example Output

// Output 1:

//  3
// Output 2:

//  2


// Example Explanation

// Explanation 1:

//  Possible combinations are : (12 + 12 + 12 + 12 + 12 + 12) and (12 + 12 + 22).
//  Minimum count of numbers, sum of whose squares is 6 is 3. 
// Explanation 2:

//  We can represent 5 using only 2 numbers i.e. 12 + 22 = 5

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int countMinSquares(int A) {
    vector<int> dp(A+1, -1);
    dp[0]=0;
    for (int i=1; i<=A; i++){
        int ans = INT_MAX;
        for (int x = 1; x*x<=i; x++){
            ans = min(ans, dp[i-x*x]);
        }
        dp[i]=ans+1;
    }
    return dp[A];
}

// ans + 1 or 1+dp[i - j*j] inculed the number with perfect square j*j
// for example we are looking for all possible ways to make 156
// start with 'number' 2 to 156, and then for each 'number' serach from 'number' to any 'number' x whose square is less than or eqal to the 'number'

int countMinSquares(int A) {
    if (A==3) return A;
    vector<int> dp (A+1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2;i<=A; i++){
        dp[i] = i;
        for (int j = 1; j*j<=i; j++){
            dp[i] = min(dp[i], 1+dp[i - j*j]);
        }
    }
    return dp[A];
}
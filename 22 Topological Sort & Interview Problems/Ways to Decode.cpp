// https://www.scaler.com/academy/mentee-dashboard/class/297857/homework/problems/10?navref=cl_tt_lst_sl

// Problem Description

// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message denoted by string A containing digits, determine the total number of ways to decode it modulo 109 + 7.



// Problem Constraints

// 1 <= length(A) <= 105



// Input Format

// The first and the only argument is a string A.



// Output Format

// Return an integer, representing the number of ways to decode the string modulo 109 + 7.



// Example Input

// Input 1:

//  A = "12"
// Input 2:

//  A = "8"


// Example Output

// Output 1:

//  2
// Output 2:

//  1


// Example Explanation

// Explanation 1:

//  Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
//  The number of ways decoding "12" is 2.
// Explanation 2:

//  Given encoded message "8", it could be decoded as only "H" (8).
//  The number of ways decoding "8" is 1.

 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDecodings(string A) {
    int n = A.size();
    if (A[0] == '0') return 0;
    if (n==1) return 1;

    int MOD = 1e9 + 7;

    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i=2; i<=n; i++){
        int digit_1 = A[i-1] - '0';
        int digit_2 = (A[i-2] - '0')*10 + digit_1;

        if (digit_1>=1 && digit_1<=9){
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        }

        if (digit_2>=10 && digit_2<=26){
            dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    return dp[n];
}


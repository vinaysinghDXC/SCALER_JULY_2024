// https://www.scaler.com/academy/mentee-dashboard/class/297877/homework/problems/368?navref=cl_tt_lst_sl

// Problem Description

// Find out the number of A digit positive numbers, whose digits on being added equals to a given number B.

// Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

// Since the answer can be large, output answer modulo 1000000007



// Problem Constraints

// 1 <= A <= 1000

// 1 <= B <= 10000



// Input Format

// First argument is the integer A

// Second argument is the integer B



// Output Format

// Return a single integer, the answer to the problem



// Example Input

// Input 1:

//  A = 2
//  B = 4
// Input 2:

//  A = 1
//  B = 3


// Example Output

// Output 1:

//  4
// Output 2:

//  1


// Example Explanation

// Explanation 1:

//  Valid numbers are {22, 31, 13, 40}
//  Hence output 4.
// Explanation 2:

//  Only valid number is 3
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solve(int A, int B) {
    int MOD = 1000000007;
    if (B == 0 || B > 9 * A) return 0;

    vector<vector<int> > dp(A + 1, vector<int>(B + 1, 0));

    for (int digit = 1; digit <= 9; ++digit) {
        if (digit <= B) dp[1][digit] = 1;
        // cout<<"dp[1]["<<digit<<"]"<<dp[1][digit]<<endl;
    }
    // cout<<endl;

    for (int i = 2; i <= A; ++i) {
        for (int j = 0; j <= B; ++j) {
            for (int digit = 0; digit <= 9; ++digit) {
                if (j >= digit) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - digit]) % MOD;
                }
            }
        }
    }

    return dp[A][B];
}

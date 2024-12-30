// https://www.scaler.com/academy/mentee-dashboard/class/297865/assignment/problems/317?navref=cl_tt_nv

// Problem Description

// Given a string A. Find the rank of the string amongst its permutations sorted lexicographically.
// Assume that no characters are repeated.

// Note: The answer might not fit in an integer, so return your answer % 1000003



// Problem Constraints

// 1 <= |A| <= 1000



// Input Format

// First argument is a string A.



// Output Format

// Return an integer denoting the rank of the given string.



// Example Input

// Input 1:

// A = "acb"
// Input 2:

// A = "a"


// Example Output

// Output 1:

// 2
// Output 2:

// 1


// Example Explanation

// Explanation 1:

// Given A = "acb".
// The order permutations with letters 'a', 'c', and 'b' : 
// abc
// acb
// bac
// bca
// cab
// cba
// So, the rank of A is 2.
// Explanation 2:

// Given A = "a".
// Rank is clearly 1.

int Solution::findRank(string A) {
    int MOD=1000003;
    int n = A.size();
    long long rank = 1;

    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    for (int i = 0; i < n; i++) {//for each character find all with permutations that are smaller
        int smallerChars = 0;
        
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[i]) {
                smallerChars++;
            }
        }
        
        rank = (rank + smallerChars * fact[n - i - 1]) % MOD;
    }

    return rank;
}

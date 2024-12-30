// https://www.scaler.com/academy/mentee-dashboard/class/297885/homework/problems/1226?navref=cl_tt_nv_dd

// Problem Description

// Misha likes finding all Subarrays of an Array. Now she gives you an array A of N elements and told you to find the number of subarrays of A, that have unique elements.

// Since the number of subarrays could be large, return value % 109 +7.



// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i] <= 106



// Input Format

// The only argument given is an Array A, having N integers.



// Output Format

// Return the number of subarrays of A, that have unique elements.



// Example Input

// Input 1:

//  A = [1, 1, 3]
// Input 2:

//  A = [2, 1, 2]


// Example Output

// Output 1:

//  4
// Output 1:

//  5


// Example Explanation

// Explanation 1:

//  Subarrays of A that have unique elements only:
//  [1], [1], [1, 3], [3]
// Explanation 2:

//  Subarrays of A that have unique elements only:
//  [2], [1], [2, 1], [1, 2], [2]


int Solution::solve(vector<int> &A) {
    unordered_map<int, int> freq;
    int mod = 1e9 + 7;
    long long count = 0;
    int l = 0;

    for (int r = 0; r < A.size(); ++r) {
        freq[A[r]]++;

        while (freq[A[r]] > 1) {
            freq[A[l]]--;
            l++;
        }
        count = (count + (r - l + 1)) % mod;
    }
    return count;
}

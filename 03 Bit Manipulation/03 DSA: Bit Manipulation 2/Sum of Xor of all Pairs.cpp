// https://www.scaler.com/academy/mentee-dashboard/class/236094/homework/problems/35183?navref=cl_tt_nv

// Problem Description

// Given an array A of N integers. Find the sum of bitwise XOR all pairs of numbers in the array.

// Since the answer can be large, return the remainder after the dividing the answer by 109+7.



// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i] < 109



// Input Format

// Only argument A is an array of integers



// Output Format

// Return an integer denoting the sum of xor of all pairs of number in the array.



// Example Input

// Input 1:
// A = [1, 2, 3]
// Input 2:
// A = [3, 4, 2]


// Example Output

// Output 1:
// 6
// Output 2:
// 14


// Example Explanation

// For Input 1:
// Pair    Xor
// {1, 2}  3
// {1, 3}  2
// {2, 3}  1
// Sum of xor of all pairs = 3 + 2 + 1 = 6.
// For Input 2:
// Pair    Xor
// {3, 4}  7
// {3, 2}  1
// {4, 2}  6
// Sum of xor of all pairs = 7 + 1 + 6 = 14.

int Solution::solve(vector<int> &A) {

    int MOD = 1e9 + 7;
    int n = A.size();
    long long ans = 0;

    // Iterate over all 32 bits
    for (int i = 0; i < 32; i++) {
        long long count1 = 0, count0 = 0;

        // Count numbers with i-th bit set and not set
        for (int j = 0; j < n; j++) {
            if (A[j] & (1 << i)) {
                count1++;
            } else {
                count0++;
            }
        }

        long long contribution = (count1 * count0) % MOD;
        contribution = (contribution * (1LL << i)) % MOD;

        ans = (ans + contribution) % MOD;
    }

    return ans;
}

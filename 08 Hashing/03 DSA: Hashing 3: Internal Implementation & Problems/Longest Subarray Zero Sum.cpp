// https://www.scaler.com/academy/mentee-dashboard/class/297885/assignment/problems/27742?navref=cl_tt_crd_nm

// Problem Description

// Given an array A of N integers.
// Find the length of the longest subarray in the array which sums to zero.

// If there is no subarray which sums to zero then return 0.



// Problem Constraints

// 1 <= N <= 105
// -109 <= A[i] <= 109


// Input Format

// Single argument which is an integer array A.


// Output Format

// Return an integer.


// Example Input

// Input 1:

//  A = [1, -2, 1, 2]
// Input 2:

//  A = [3, 2, -1]


// Example Output

// Output 1:

// 3
// Output 2:

// 0


// Example Explanation

// Explanation 1:

//  [1, -2, 1] is the largest subarray which sums up to 0.
// Explanation 2:

//  No subarray sums up to 0.



int Solution::solve(vector<int> &A) {
    unordered_map<long long, int> presum;

    long long sum = 0;
    int max_len = 0;

    for (int i = 0; i < A.size(); i++) {

        sum += A[i];

        if (sum == 0) {
            max_len = i + 1;
        }

        if (presum.find(sum) != presum.end()) {
            max_len = max(max_len, i - presum[sum]);
        } else {
            presum[sum] = i;
        }
    }

    return max_len;    
}

// https://www.scaler.com/academy/mentee-dashboard/class/236094/homework/problems/383?navref=cl_tt_nv

// Problem Description

// Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.



// Problem Constraints

// 2 <= length of the array <= 100000
// 0 <= A[i] <= 109



// Input Format

// First and only argument of input contains an integer array A.



// Output Format

// Return a single integer denoting minimum xor value.



// Example Input

// Input 1:

//  A = [0, 2, 5, 7]
// Input 2:

//  A = [0, 4, 7, 9]


// Example Output

// Output 1:

//  2
// Output 2:

//  3


// Example Explanation

// Explanation 1:

//  0 xor 2 = 2

int Solution::findMinXor(vector<int> &A) {
    int n = A.size();

    sort(A.begin(), A.end());

    int minXOR = INT_MAX;

    // Iterate through the array and find the minimum XOR
    for (int i = 0; i < n - 1; i++) {
        int xorValue = A[i] ^ A[i + 1];
        minXOR = min(minXOR, xorValue);
    }

    return minXOR;
}

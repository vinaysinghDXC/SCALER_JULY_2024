// https://www.scaler.com/academy/mentee-dashboard/class/236094/assignment/problems/35182?navref=cl_tt_nv

// Problem Description

// Given an array A of length N where all the elements are distinct and are in the range [1, N+2].

// Two numbers from the range [1, N+2] are missing from the array A. Find the two missing numbers.



// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i] <= N+2

// The elements of array A are distinct



// Input Format

// Only argument A is an array of integers



// Output Format

// Return a sorted array of size 2 denoting the missing elements.



// Example Input

// Input 1:
// A = [3, 2, 4]
// Input 2:
// A = [5, 1, 3, 6]


// Example Output

// Output 1:
// [1, 5]
// Output 2:
// [2, 4]


// Example Explanation

// For Input 1:
// The missing numbers are 1 and 5.
// For Input 2:
// The missing numbers are 2 and 4.

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    int totalXor = 0;
    int arrayXor = 0;

    // XOR all numbers from 1 to N+2
    for (int i = 1; i <= n + 2; ++i) {
        totalXor ^= i;
    }

    // XOR all elements in the array
    for (int num : A) {
        arrayXor ^= num;
    }

    // XOR of totalXor and arrayXor gives XOR of the two missing numbers
    int missingXor = totalXor ^ arrayXor;

    // Find the rightmost set bit in missingXor
    int rightmostSetBit = missingXor & -missingXor;

    int num1 = 0, num2 = 0;

    // Partition numbers into two groups based on the rightmost set bit
    for (int i = 1; i <= n + 2; ++i) {
        if (i & rightmostSetBit) {
            num1 ^= i;
        } else {
            num2 ^= i;
        }
    }

    for (int num : A) {
        if (num & rightmostSetBit) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }

    vector<int> result = {num1, num2};
    sort(result.begin(), result.end());

    return result;
}

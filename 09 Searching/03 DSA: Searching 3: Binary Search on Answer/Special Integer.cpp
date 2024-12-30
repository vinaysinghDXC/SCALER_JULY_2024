// https://www.scaler.com/academy/mentee-dashboard/class/236088/homework/problems/4133?navref=cl_tt_nv

// Problem Description

// Given an array of integers A and an integer B, find and return the maximum value K such that there is no subarray in A of size K with the sum of elements greater than B.



// Problem Constraints

// 1 <= |A| <= 100000
// 1 <= A[i] <= 10^9

// 1 <= B <= 10^9



// Input Format

// The first argument given is the integer array A.

// The second argument given is integer B.



// Output Format

// Return the maximum value of K (sub array length).



// Example Input

// Input 1:

// A = [1, 2, 3, 4, 5]
// B = 10
// Input 2:

// A = [5, 17, 100, 11]
// B = 130


// Example Output

// Output 1:

//  2
// Output 2:

//  3


// Example Explanation

// Explanation 1:

// For K = 5, There are subarrays [1, 2, 3, 4, 5] which has a sum > B
// For K = 4, There are subarrays [1, 2, 3, 4], [2, 3, 4, 5] which has a sum > B
// For K = 3, There is a subarray [3, 4, 5] which has a sum > B
// For K = 2, There were no subarray which has a sum > B.
// Constraints are satisfied for maximal value of 2.
// Explanation 2:

// For K = 4, There are subarrays [5, 17, 100, 11] which has a sum > B
// For K = 3, There were no subarray which has a sum > B.
// Constraints are satisfied for maximal value of 3.

bool isValid(const vector<int>& A, int K, int B) {
    int n = A.size();
    long long current_sum = 0;

    for (int i = 0; i < K; ++i) {
        current_sum += A[i];
    }

    if (current_sum > B) return false;

    for (int i = K; i < n; ++i) {
        current_sum += A[i] - A[i - K];  // Slide the window
        if (current_sum > B) return false;
    }
    
    return true;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int low = 1, high = n, result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (isValid(A, mid, B)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return result;
}

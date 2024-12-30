// https://www.scaler.com/academy/mentee-dashboard/class/236124/homework/problems/4366?navref=cl_tt_nv

// Problem Description

// Given an array A of both positive and negative integers.



// Your task is to compute the sum of minimum and maximum elements of all sub-array of size B.

// NOTE: Since the answer can be very large, you are required to return the sum modulo 109 + 7.





// Problem Constraints

// 1 <= size of array A <= 105

// -109 <= A[i] <= 109

// 1 <= B <= size of array



// Input Format

// The first argument denotes the integer array A.
// The second argument denotes the value B



// Output Format

// Return an integer that denotes the required value.



// Example Input

// Input 1:

//  A = [2, 5, -1, 7, -3, -1, -2]
//  B = 4
// Input 2:

//  A = [2, -1, 3]
//  B = 2


// Example Output

// Output 1:

//  18
// Output 2:

//  3


// Example Explanation

// Explanation 1:

//  Subarrays of size 4 are : 
//     [2, 5, -1, 7],   min + max = -1 + 7 = 6
//     [5, -1, 7, -3],  min + max = -3 + 7 = 4      
//     [-1, 7, -3, -1], min + max = -3 + 7 = 4
//     [7, -3, -1, -2], min + max = -3 + 7 = 4   
//     Sum of all min & max = 6 + 4 + 4 + 4 = 18 
// Explanation 2:

//  Subarrays of size 2 are : 
//     [2, -1],   min + max = -1 + 2 = 1
//     [-1, 3],   min + max = -1 + 3 = 2
//     Sum of all min & max = 1 + 2 = 3 

int Solution::solve(vector<int> &A, int B) {
    int MOD=1e9+7;
    int n = A.size();    
    deque<int> minDeque, maxDeque;
    long long result = 0;

    for (int i = 0; i < n; ++i) {

        if (!minDeque.empty() && minDeque.front() <= i - B) {//remove elemtes out of the window
            minDeque.pop_front();
        }
        if (!maxDeque.empty() && maxDeque.front() <= i - B) {//remove elemtes out of the window
            maxDeque.pop_front();
        }

        while (!minDeque.empty() && A[minDeque.back()] >= A[i]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i);

        while (!maxDeque.empty() && A[maxDeque.back()] <= A[i]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(i);

        if (i >= B - 1) {
            result = (result + A[minDeque.front()] + A[maxDeque.front()]) % MOD;
            if (result < 0) result += MOD;  // Handle negative values
        }
    }
    return result;    
}

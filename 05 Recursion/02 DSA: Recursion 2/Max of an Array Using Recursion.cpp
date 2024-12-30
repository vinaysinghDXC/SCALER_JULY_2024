// Problem Description

// Given an array A of size N, write a recursive function that returns the maximum element of the array.


// Problem Constraints

// 1 <= N <= 100
// 1 <= A[i] <= 1000


// Input Format

// The first line contains the array A.


// Output Format

// A single integer is the maximum value of the array.


// Example Input

// Input 1:
// A = [12, 10, 3, 4, 5]
// Input 2:
// A = [1, 5, 80, 40]


// Example Output

// Output 1:

// 12
// Output 2:
// 80


// Example Explanation

// Explanation 1:
//  The Maximum element of the array A, [12, 10, 3, 4, 5] is 12
// Explanation 2:
//  The Maximum element of the array A, [1, 5, 80, 40] is 80

//  https://www.scaler.com/academy/mentee-dashboard/class/236076/assignment/problems/122783?navref=cl_tt_nv

int maxele(vector<int> &A, int idx){
    if(idx==A.size()-1) return A[idx];
    int newmax=maxele(A, idx+1);
    return max(newmax, A[idx]);
}

int Solution::getMax(vector<int> &A) {
    return maxele(A, 0);
}

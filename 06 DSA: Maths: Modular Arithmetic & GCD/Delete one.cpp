// https://www.scaler.com/academy/mentee-dashboard/class/236090/assignment/problems/9103?navref=cl_tt_nv

// Problem Description

// Given an integer array A of size N. You have to delete one element such that the GCD(Greatest common divisor) of the remaining array is maximum.

// Find the maximum value of GCD.



// Problem Constraints

// 2 <= N <= 105
// 1 <= A[i] <= 109



// Input Format

// First argument is an integer array A.



// Output Format

// Return an integer denoting the maximum value of GCD.



// Example Input

// Input 1:

//  A = [12, 15, 18]
// Input 2:

//  A = [5, 15, 30]




// Example Output

// Output 1:

//  6
// Output 2:

//  15




// Example Explanation

// Explanation 1:

//  If you delete 12, gcd will be 3.
//  If you delete 15, gcd will be 6.
//  If you delete 18, gcd will 3.
//  Maximum value of gcd is 6.
// Explanation 2:

//  If you delete 5, gcd will be 15.
//  If you delete 15, gcd will be 5.
//  If you delete 30, gcd will be 5.
//  Maximum value of gcd is 15.

int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    if (n == 1) return A[0];

    vector<int> prefixGCD(n), suffixGCD(n);

    // Compute prefix GCD array
    prefixGCD[0] = A[0];
    for (int i = 1; i < n; ++i) {
        prefixGCD[i] = gcd(prefixGCD[i-1], A[i]);
    }

    // Compute suffix GCD array
    suffixGCD[n-1] = A[n-1];
    for (int i = n-2; i >= 0; --i) {
        suffixGCD[i] = gcd(suffixGCD[i+1], A[i]);
    }

    // Compute maximum GCD after removing each element
    int maxGCD = max(suffixGCD[1], prefixGCD[n-2]);

    for (int i = 1; i < n-1; ++i) {
        int currentGCD = gcd(prefixGCD[i-1], suffixGCD[i+1]);
        maxGCD = max(maxGCD, currentGCD);
    }

    return maxGCD;
}
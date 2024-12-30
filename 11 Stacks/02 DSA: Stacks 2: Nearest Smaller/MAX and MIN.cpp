// https://www.scaler.com/academy/mentee-dashboard/class/236120/assignment/problems/7042?navref=cl_tt_nv

// Problem Description

// Given an array of integers A.


// The value of an array is computed as the difference between the maximum element in the array and the minimum element in the array A.

// Calculate and return the sum of values of all possible subarrays of A modulo 109+7.





// Problem Constraints

// 1 <= |A| <= 100000


// 1 <= A[i] <= 1000000




// Input Format

// The first and only argument given is the integer array A.



// Output Format

// Return the sum of values of all possible subarrays of A modulo 109+7.



// Example Input

// Input 1:


//  A = [1]

// Input 2:


//  A = [4, 7, 3, 8]



// Example Output

// Output 1:

//  0
// Output 2:

//  26


// Example Explanation

// Explanation 1:

// Only 1 subarray exists. Its value is 0.
// Explanation 2:

// value ( [4] ) = 4 - 4 = 0
// value ( [7] ) = 7 - 7 = 0
// value ( [3] ) = 3 - 3 = 0
// value ( [8] ) = 8 - 8 = 0
// value ( [4, 7] ) = 7 - 4 = 3
// value ( [7, 3] ) = 7 - 3 = 4
// value ( [3, 8] ) = 8 - 3 = 5
// value ( [4, 7, 3] ) = 7 - 3 = 4
// value ( [7, 3, 8] ) = 8 - 3 = 5
// value ( [4, 7, 3, 8] ) = 8 - 3 = 5
// sum of values % 10^9+7 = 26

int Solution::solve(vector<int> &A) {
    int n = A.size();
    if (n == 1) return A[0];

    // Calculate NSL (Nearest Smaller to Left)
    stack<int> htl;
    vector<int> nsl(n);
    for (int i = 0; i < n; i++) {
        while (!htl.empty() && A[htl.top()] >= A[i]) htl.pop();
        if (htl.empty()) nsl[i] = -1;
        else nsl[i] = htl.top();
        htl.push(i);
    }

    // Calculate NSR (Nearest Smaller to Right)
    stack<int> htr;
    vector<int> nsr(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!htr.empty() && A[htr.top()] >= A[i]) htr.pop();
        if (htr.empty()) nsr[i] = n;
        else nsr[i] = htr.top();
        htr.push(i);
    }

    // Calculate NGL (Nearest Greater to Left)
    stack<int> hgl;
    vector<int> ngl(n);
    for (int i = 0; i < n; i++) {
        while (!hgl.empty() && A[hgl.top()] <= A[i]) hgl.pop();
        if (hgl.empty()) ngl[i] = -1;
        else ngl[i] = hgl.top();
        hgl.push(i);
    }

    // Calculate NGR (Nearest Greater to Right)
    stack<int> hgr;
    vector<int> ngr(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!hgr.empty() && A[hgr.top()] <= A[i]) hgr.pop();
        if (hgr.empty()) ngr[i] = n;
        else ngr[i] = hgr.top();
        hgr.push(i);
    }

    long long  fmax=0, fmin=0;
    int mod = 1e9+7;

    for (int i = 0; i < n; i++) {
        fmax = (fmax + 1LL * A[i] * (i - ngl[i]) * (ngr[i] - i)) % mod;
        fmin = (fmin + 1LL * A[i] * (i - nsl[i]) * (nsr[i] - i)) % mod;
    }
    
    long long result = (fmax - fmin) % mod;
    
    // Ensure the result is non-negative
    if (result < 0) result += mod;

    return result;
}

// https://www.scaler.com/academy/mentee-dashboard/class/236120/assignment/problems/49?navref=cl_tt_lst_nm

// Problem Description

// Given an array of integers A.


// A represents a histogram i.e A[i] denotes the height of the ith histogram's bar. Width of each bar is 1.

// Find the area of the largest rectangle formed by the histogram.




// Problem Constraints

// 1 <= |A| <= 100000


// 1 <= A[i] <= 10000




// Input Format

// The only argument given is the integer array A.



// Output Format

// Return the area of the largest rectangle in the histogram.



// Example Input

// Input 1:

//  A = [2, 1, 5, 6, 2, 3]
// Input 2:

//  A = [2]


// Example Output

// Output 1:

//  10
// Output 2:

//  2


// Example Explanation

// Explanation 1:


// The largest rectangle has area = 10 unit. Formed by A[3] to A[4].

// Explanation 2:


// Largest rectangle has area 2.

int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    if (n == 1) return A[0];

    stack<int> htl;
    vector<int> nsl(n);

    // Calculate NSL (Nearest Smaller to Left)
    for (int i = 0; i < n; i++) {
        while (!htl.empty() && A[htl.top()] >= A[i]) htl.pop();
        if (htl.empty()) nsl[i] = -1;
        else nsl[i] = htl.top();
        htl.push(i);
    }

    stack<int> htr;
    vector<int> nsr(n);

    // Calculate NSR (Nearest Smaller to Right)
    for (int i = n - 1; i >= 0; i--) {
        while (!htr.empty() && A[htr.top()] >= A[i]) htr.pop();
        if (htr.empty()) nsr[i] = n;
        else nsr[i] = htr.top();
        htr.push(i);
    }

    int ans = 0;

    // Calculate the maximum area of the rectangle
    for (int i = 0; i < n; i++) {
        int width = nsr[i] - nsl[i] - 1;  // Width of the rectangle with height A[i]
        ans = max(ans, A[i] * width);
    }

	return ans;
}

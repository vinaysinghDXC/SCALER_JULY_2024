// https://www.scaler.com/academy/mentee-dashboard/class/297845/assignment/problems/9347?navref=cl_tt_lst_sl

// Problem Description

// Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

// Also given an integer C which represents knapsack capacity.

// Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

// NOTE: You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).



// Problem Constraints

// 1 <= N <= 500

// 1 <= C, B[i] <= 106

// 1 <= A[i] <= 50



// Input Format

// First argument is an integer array A of size N denoting the values on N items.

// Second argument is an integer array B of size N denoting the weights on N items.

// Third argument is an integer C denoting the knapsack capacity.



// Output Format

// Return a single integer denoting the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.



// Example Input

// Input 1:

//  A = [6, 10, 12]
//  B = [10, 20, 30]
//  C = 50
// Input 2:

//  A = [1, 3, 2, 4]
//  B = [12, 13, 15, 19]
//  C = 10


// Example Output

// Output 1:

//  22
// Output 2:

//  0


// Example Explanation

// Explanation 1:

//  Taking items with weight 20 and 30 will give us the maximum value i.e 10 + 12 = 22
// Explanation 2:

//  Knapsack capacity is 10 but each item has weight greater than 10 so no items can be considered in the knapsack therefore answer is 0.


int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int sum = 0;
    for (int i : A) sum += i;

    int n = A.size();
    vector<vector<int>> kdp(n + 1, vector<int>(sum + 1, INT_MAX));

    for (int i = 0; i <= n; i++) kdp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            int f1 = kdp[i - 1][j]; //don't select the current item
            int f2 = INT_MAX;

            if (j - A[i - 1] >= 0 && kdp[i - 1][j - A[i - 1]] != INT_MAX) {
                f2 = B[i - 1] + kdp[i - 1][j - A[i - 1]]; //select the current item
            }

            kdp[i][j] = min(f1, f2);
        }
    }

    for (int i = sum; i >= 0; i--) {
        if (kdp[n][i] <= C) return i; // i is achievable with weight ≤ `C`
    }
    return 0;
}

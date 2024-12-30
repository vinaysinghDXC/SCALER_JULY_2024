// https://www.scaler.com/academy/mentee-dashboard/class/297905/assignment/problems/35883?navref=cl_tt_lst_sl

// Problem Description

// Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

// Also given an integer C which represents knapsack capacity.

// Find out the maximum total value that we can fit in the knapsack. If the maximum total value is ans, then return ⌊ans × 100⌋ , i.e., floor of (ans × 100).

// NOTE:

// You can break an item for maximizing the total value of the knapsack



// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i], B[i] <= 103

// 1 <= C <= 103




// Input Format

// First argument is an integer array A of size N denoting the values on N items.

// Second argument is an integer array B of size N denoting the weights on N items.

// Third argument is an integer C denoting the knapsack capacity.




// Output Format

// Return a single integer denoting the maximum total value of A such that sum of the weights of this subset is smaller than or equal to C.



// Example Input

// Input 1:

//  A = [60, 100, 120]
//  B = [10, 20, 30]
//  C = 50
// Input 2:

//  A = [10, 20, 30, 40]
//  B = [12, 13, 15, 19]
//  C = 10


// Example Output

// Output 1:

//  24000
// Output 2:

//  2105


// Example Explanation

// Explanation 1:

// Taking the full items with weight 10 and 20 and 2/3 of the item with weight 30 will give us 
// the maximum value i.e 60 + 100 + 80 = 240. So we return 24000.
// Explanation 2:

// Taking 10/19 the fourth item gives us the maximum value i.e. 21.0526. So we return 2105.


// struct frac{
//     int val, wt;
//     frac(int val, int wt){
//         this->val=val;
//         this->wt=wt;
//     }
// };


//-----------------NOTE------------------//
// Floating-point arithmetic may result in a value like 254.999999999 instead of 255. 
// Adding a small epsilon value (1e-9) before applying floor ensures the result is correctly floored to 255.

#include<iostream>
#include <vector>
using namespace std;

int solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<pair<double, int>> createpair;

    for (int i = 0; i < n; ++i) {
        createpair.push_back({A[i] * 1.0 / B[i], i});
    }

    sort(createpair.rbegin(), createpair.rend());

    double ans = 0;

    for (int i = 0; i < n; ++i) {
        int idx = createpair[i].second;
        if (B[idx] <= C) {
            ans += A[idx];
            C -= B[idx];
        } else {
            ans += A[idx] * (C * 1.0) / (B[idx] * 1.0);
            break;
        }
    }

    return static_cast<int>(floor(ans * 100 + 1e-9));
}

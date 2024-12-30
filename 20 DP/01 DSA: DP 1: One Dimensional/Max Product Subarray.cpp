// https://www.scaler.com/academy/mentee-dashboard/class/297861/homework/problems/9/submissions

// Problem Description

// Given an integer array A of size N. Find the contiguous subarray within the given array (containing at least one number) which has the largest product.

// Return an integer corresponding to the maximum product possible.

// NOTE: Answer will fit in 32-bit integer value.



// Problem Constraints

// 1 <= N <= 5 * 105

// -100 <= A[i] <= 100



// Input Format

// First and only argument is an integer array A.



// Output Format

// Return an integer corresponding to the maximum product possible.



// Example Input

// Input 1:

//  A = [4, 2, -5, 1]
// Input 2:

//  A = [-3, 0, -5, 0]


// Example Output

// Output 1:

//  8
// Output 2:

//  0


// Example Explanation

// Explanation 1:

//  We can choose the subarray [4, 2] such that the maximum product is 8.
// Explanation 2:

//  0 will be the maximum product possible.
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int maxProduct(const vector<int> &A) {
    int n = A.size();
    int currmax = A[0];
    int currmin = A[0];
    int maxprod = A[0];
  
    for (int i = 1; i < n; i++) {
        int temp = max({ A[i], A[i] * currmax, A[i] * currmin });
        
        currmin = min({ A[i], A[i] * currmax, A[i] * currmin });
      
        currmax = temp;
      
        maxprod = max(maxprod, currmax);
    }
    return maxprod;
}

// https://www.scaler.com/academy/mentee-dashboard/class/297905/assignment/problems/9340?navref=cl_tt_nv

// Problem Description

// Given a knapsack weight A and a set of items with certain value B[i] and weight C[i], we need to calculate maximum amount that could fit in this quantity.

// This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.



// Problem Constraints

// 1 <= A <= 1000

// 1 <= |B| <= 1000

// 1 <= B[i] <= 1000

// 1 <= C[i] <= 1000



// Input Format

// First argument is the Weight of knapsack A

// Second argument is the vector of values B

// Third argument is the vector of weights C



// Output Format

// Return the maximum value that fills the knapsack completely



// Example Input

// Input 1:

// A = 10
// B = [5]
// C = [10]
// Input 2:

// A = 10
// B = [6, 7]
// C = [5, 5]


// Example Output

// Output 1:

//  5
// Output 2:

// 14


// Example Explanation

// Explanation 1:

// Only valid possibility is to take the given item.
// Explanation 2:

// Take the second item twice.
#include<iostream>
#include <vector>
using namespace std;

int maxunbound(int A, vector<int> &B, vector<int> &C, vector<int> &kdp){
    if (A==0) return 0;

    int ans=0;
    if (kdp[A]!=-1) return kdp[A];
    for (int i = 0; i<B.size(); i++){
        if (A >= C[i]) ans = max(ans, B[i]+maxunbound(A-C[i], B, C, kdp));
    }
    kdp[A]=ans;
    return kdp[A];
}

int solve(int A, vector<int> &B, vector<int> &C) {
    vector<int> kdp(A+1, -1);
    return maxunbound(A, B, C, kdp);
}

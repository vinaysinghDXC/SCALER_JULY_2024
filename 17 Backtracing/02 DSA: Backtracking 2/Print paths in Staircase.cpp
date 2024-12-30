// https://www.scaler.com/academy/mentee-dashboard/class/297913/assignment/problems/125076?navref=cl_tt_nv

// Problem Description

// You are climbing a staircase and it takes A steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// You need to return all the distinct ways to climb to the top in lexicographical order.



// Problem Constraints

// 2 <= A <= 25



// Input Format

// The first and the only argument contains an integer A, the number of steps.



// Output Format

// Return an 2-D Integer Array, which denotes all the unique valid paths to reach the top.



// Example Input

// Input 1:

//  A = 2
// Input 2:

//  A = 3



// Example Output

// Output 1:

// [ [1, 1], [2] ]
// Output 2:

// [ [1, 1, 1], [1, 2], [2, 1] ]



// Example Explanation

// Explanation 1:

//  Distinct ways to reach top: 1 + 1, 2.
// Explanation 2:

//  Distinct ways to reach top: 1 + 1 + 1, 1 + 2, 2 + 1.

void stair(int A, vector<int> arr, vector<vector<int>>& ans) {
    if (A == 0) {
        ans.push_back(arr);  // Directly push the vector
        return;
    }

    arr.push_back(1);
    stair(A - 1, arr, ans);
    arr.pop_back();

    if (A >= 2) {
        arr.push_back(2);
        stair(A - 2, arr, ans);
        arr.pop_back();   
    }
}

vector<vector<int>> Solution::WaysToClimb(int A) {
    vector<vector<int>> ans;
    vector<int> arr;
    stair(A, arr, ans);
    return ans;
}

// https://www.scaler.com/academy/mentee-dashboard/class/297897/assignment/problems/89434?navref=cl_tt_nv

// Problem Description

// Given a set of distinct integers A, return all possible subsets that can be formed from the elements of array A.



// Problem Constraints

// 1 ≤ |A| ≤ 16

// INT_MIN ≤ A[i] ≤ INT_MAX

// Array A is given in increasing order.

// All elements of array A are distinct.



// Input Format

// First and only argument of input contains a single integer array A.



// Output Format

// Return a vector of vectors denoting the answer in any order.



// Example Input

// Input 1:

// A = [1]
// Input 2:

// A = [1, 2, 3]


// Example Output

// Output 1:

// [
//     []
//     [1]
// ]
// Output 2:

// [
//  []
//  [1]
//  [1, 2]
//  [1, 2, 3]
//  [1, 3]
//  [2]
//  [2, 3]
//  [3]
// ]


// Example Explanation

// Explanation:

// You can see that these are all possible subsets.

class Solution {
   public:
    void generate(vector<int> &A, int idx, vector<int> current, vector<vector<int> > &ans){
        if (idx==A.size()){
            ans.push_back(current);
            return;
        }

        generate(A, idx+1, current, ans);
        current.push_back(A[idx]);
        generate(A, idx+1, current, ans);
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &A) {
        // code here
        int idx=0;
        vector<int> current;
        vector<vector<int> > ans;

        generate(A, idx, current, ans);
        return ans;
    }
};

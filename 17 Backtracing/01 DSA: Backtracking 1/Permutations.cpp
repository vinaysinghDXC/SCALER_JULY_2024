// https://www.scaler.com/academy/mentee-dashboard/class/297897/assignment/problems/138?navref=cl_tt_lst_nm

// Problem Description

// Given an integer array A of size N denoting collection of numbers , return all possible permutations.

// NOTE:

// No two entries in the permutation sequence should be the same.
// For the purpose of this problem, assume that all the numbers in the collection are unique.
// Return the answer in any order
// WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. 
// Example : next_permutations in C++ / itertools.permutations in python.
// If you do, we will disqualify your submission retroactively and give you penalty points.


// Problem Constraints

// 1 <= N <= 9



// Input Format

// Only argument is an integer array A of size N.



// Output Format

// Return a 2-D array denoting all possible permutation of the array.



// Example Input

// A = [1, 2, 3]


// Example Output

// [ [1, 2, 3]
//   [1, 3, 2]
//   [2, 1, 3] 
//   [2, 3, 1] 
//   [3, 1, 2] 
//   [3, 2, 1] ]


// Example Explanation

// All the possible permutation of array [1, 2, 3].

void findpermutations(vector<int> &A, vector<vector<int>> &ans, int idx, vector<int> current, vector<bool> &used) {
    if (idx == A.size()) {
        ans.push_back(current);
        return;
    }

    for (int i = 0; i < A.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(A[i]);
            findpermutations(A, ans, idx + 1, current, used);
            current.pop_back();  //remove the last added element
            used[i] = false;     //mark the element as unused
        }
    }
}

vector<vector<int>> Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    int idx = 0;
    vector<int> current;
    vector<bool> used(A.size(), false);
    findpermutations(A, ans, idx, current, used);
    return ans;
}

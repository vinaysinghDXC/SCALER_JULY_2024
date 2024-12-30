// https://www.scaler.com/academy/mentee-dashboard/class/236130/homework/problems/4258?navref=cl_tt_nv

// Problem Description

// Given preorder traversal of a binary tree, check if it is possible that it is also a preorder traversal of a Binary Search Tree (BST), where each internal node (non-leaf nodes) have exactly one child.



// Problem Constraints

// 1 <= number of nodes <= 100000



// Input Format

// First and only argument is an integer array denoting the preorder traversal of binary tree.



// Output Format

// Return a string "YES" if true else "NO".



// Example Input

// Input 1:

//  A : [4, 10, 5, 8]
// Input 2:

//  A : [1, 5, 6, 4]


// Example Output

// Output 1:

//  "YES"
// Output 2:

//  "NO"


// Example Explanation

// Explanation 1:

//  The possible BST is:
//             4
//              \
//              10
//              /
//              5
//               \
//               8
// Explanation 2:

//  There is no possible BST which have the above preorder traversal.

string Solution::solve(vector<int> &A) {
    int lrange=INT_MIN;
    int rrange=INT_MAX;
    int root=A[0];
    for (int i=1; i<A.size(); i++){
        if (A[i]>root){
            lrange=root;
        }
        else{
            rrange=root;
        }
        
        if (A[i]<lrange || A[i]>rrange) return "NO";

        root=A[i];
    }
    return "YES";
}

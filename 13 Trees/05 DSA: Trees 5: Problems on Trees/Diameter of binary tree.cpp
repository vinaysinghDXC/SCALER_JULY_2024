// https://www.scaler.com/academy/mentee-dashboard/class/297917/assignment/problems/9256?navref=cl_tt_nv_dd

// Problem Description

// Given a Binary Tree A consisting of N integer nodes, you need to find the diameter of the tree.

// The diameter of a tree is the number of edges on the longest path between two nodes in the tree.



// Problem Constraints

// 0 <= N <= 105



// Input Format

// First and only Argument represents the root of binary tree A.



// Output Format

// Return an single integer denoting the diameter of the tree.



// Example Input

// Input 1:

//            1
//          /   \
//         2     3
//        / \
//       4   5
// Input 2:

//             1
//           /   \
//          2     3
//         / \     \
//        4   5     6


// Example Output

// Output 1:

//  3
// Output 2:

//  4


// Example Explanation

// Explanation 1:

//  Longest Path in the tree is 4 -> 2 -> 1 -> 3 and the number of edges in this path is 3 so diameter is 3.
// Explanation 2:

//  Longest Path in the tree is 4 -> 2 -> 1 -> 3 -> 6 and the number of edges in this path is 4 so diameter is 4.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* A, int &dia){
    if (A==NULL) return -1;

    int lh = height(A->left, dia);
    int rh = height(A->right, dia);

    dia=max(lh+rh+2, dia);

    return (max(lh, rh) + 1);
}

int Solution::solve(TreeNode* A) {
    int dia=0;
    height(A, dia);
    return dia;
}
